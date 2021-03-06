
#include "dispatcher.hpp"

using namespace fcgisrv;

std::shared_ptr<IHandler> Dispatcher::select(
    std::shared_ptr<IServer_Request_Response> req_res_ptr) const {
    auto raw_method = req_res_ptr->get_parameter("REQUEST_METHOD");

    if (!raw_method) {
        return m_error_set.get_error(500);
    }

    if (!m_authenticator.is_valid(req_res_ptr)) {
        return m_error_set.get_error(401);
    }

    auto key = build_uri(req_res_ptr->get_parameter("PATH_INFO"));

    auto it = m_dispatch_matrix.find(key);
    if (it == m_dispatch_matrix.end()) {
        return m_error_set.get_error(404);
    }

    auto actual_method = Http_Method::from_string(raw_method);
    if (actual_method == Http_Method::Not_a_method) {
        return m_error_set.get_error(405);
    }

    const auto &entry = it->second;

    auto h_it = entry.find(actual_method);
    if (h_it == entry.end()) {
        return m_error_set.get_error(405);
    }

    return h_it->second;
}

std::string Dispatcher::build_uri(const char *raw) const {
    std::string key;
    if (raw) {
        key = raw;
        add_end_slash(key);
    } else { // PATH_INFO is not here we are aiming for /
        key = "/";
    }
    return key;
}

void Dispatcher::add_end_slash(std::string &uri) const {
    if (uri.size() == 0)
        return;
    if (uri.at(uri.size() - 1) != '/') {
        uri = uri + "/";
    }
}

void Dispatcher::dispatch(std::shared_ptr<IServer_Request_Response> req_ptr) {
    std::shared_ptr<IHandler> current_handler = select(req_ptr);

    current_handler->handle(req_ptr);
}

void Dispatcher::add_endpoint(std::string uri, Http_Method meth,
                              std::shared_ptr<IHandler> handler) {
    if (!handler)
        throw std::invalid_argument("Endpoint pointer is null");

    add_end_slash(uri);

    auto endpoint_it = m_dispatch_matrix.find(uri);
    if (endpoint_it == m_dispatch_matrix.end()) {
        m_dispatch_matrix[uri] = HandlerMap_t{{meth, handler}};
    } else {
        HandlerMap_t &entry = endpoint_it->second;
        if (entry.find(meth) != entry.end()) {
            entry[meth] = handler;
        } else {
            throw std::invalid_argument("Endpoint with method already exist");
        }
    }
}
