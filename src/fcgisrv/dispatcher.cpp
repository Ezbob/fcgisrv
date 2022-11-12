
#include "dispatcher.hpp"

using namespace fcgisrv;

namespace {
    void add_slash(std::string &uri) {
        if (uri.size() == 0) {
            uri = "/";
        }
        if (uri.at(uri.size() - 1) != '/') {
            uri = uri + "/";
        }
    }
};

std::shared_ptr<IHandler>
    Dispatcher::select(Fcgi_Request_Response req_res_ptr) const {
    std::string raw_method;
    if (!req_res_ptr->parameter("REQUEST_METHOD", raw_method)) {
        return m_error_set.get_error(500);
    }

    if (!m_authenticator.is_valid(req_res_ptr)) {
        return m_error_set.get_error(401);
    }

    std::string uri;
    if (!req_res_ptr->parameter("PATH_INFO", uri)) {
        return m_error_set.get_error(500);
    }
    add_slash(uri);

    auto it = m_dispatch_matrix.find(uri);
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

void Dispatcher::dispatch(Fcgi_Request_Response req_ptr) {
    std::shared_ptr<IHandler> current_handler = select(req_ptr);

    current_handler->handle(req_ptr);
}

void Dispatcher::add_endpoint(std::string uri, Http_Method meth,
                              std::shared_ptr<IHandler> handler) {
    if (!handler) {
        throw std::invalid_argument("Endpoint pointer is null");
    }

    add_slash(uri);

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
