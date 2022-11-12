
#include "fcgi_server_request_response.hpp"

#include "iformatted_response.hpp"

using namespace fcgisrv;

Fcgi_Server_Request_Response::Fcgi_Server_Request_Response()
    : m_is_accepted(false)
    , m_log_stream(&m_log_stream_buf) {
    FCGX_InitRequest(&m_request, 0, 0);
    m_is_accepted = (FCGX_Accept_r(&m_request) == 0);
    if (m_is_accepted) {
        m_log_stream_buf.attach(m_request.err);
    }
}

Fcgi_Server_Request_Response::~Fcgi_Server_Request_Response() {
    if (m_is_accepted) {
        FCGX_Finish_r(&m_request);
    }
}

bool Fcgi_Server_Request_Response::is_accepted() const {
    return m_is_accepted;
}

int Fcgi_Server_Request_Response::respond_with(IFormatted_Response &res) {
    std::string rendered = res.render();
    return FCGX_PutStr(rendered.c_str(), static_cast<int>(rendered.size()), m_request.out);
}

int Fcgi_Server_Request_Response::respond_with(std::string const &res) {
    return FCGX_PutStr(res.c_str(), static_cast<int>(res.size()), m_request.out);
}

std::ostream &Fcgi_Server_Request_Response::log_out() {
    return m_log_stream;
}

bool Fcgi_Server_Request_Response::parameter(std::string const &name,
                                             std::string &out) const {
    const char *param = FCGX_GetParam(name.c_str(), m_request.envp);
    if (param == nullptr) {
        return false;
    }
    out = param;
    return true;
}

const std::vector<std::string>
    Fcgi_Server_Request_Response::parameters() const {
    std::vector<std::string> res;
    for (size_t i = 0; m_request.envp[i] != nullptr; ++i) {
        res.push_back(m_request.envp[i]);
    }
    return res;
}

std::shared_ptr<Fcgi_Server_Request_Response>
    Fcgi_Server_Request_Response::get() {
    return shared_from_this();
}
