
#include "fcgi_server_request_response.hpp"

#include "iformatted_response.hpp"

using namespace fcgisrv;

Fcgi_Server_Request_Response::Fcgi_Server_Request_Response()
    : m_is_accepted(false)
    , m_log_stream(&m_log_stream_buf) {
    FCGX_InitRequest(&m_request, 0, 0);
}

Fcgi_Server_Request_Response::~Fcgi_Server_Request_Response() {
    if (m_is_accepted) {
        FCGX_Finish_r(&m_request);
    }
}

bool Fcgi_Server_Request_Response::accept() {
    m_is_accepted = (FCGX_Accept_r(&m_request) == 0);
    if (m_is_accepted) {
        m_log_stream_buf.attach(m_request.err);
    }
    return m_is_accepted;
}

bool Fcgi_Server_Request_Response::is_accepted() {
    return m_is_accepted;
}

int Fcgi_Server_Request_Response::respond_with(IFormatted_Response &res) {
    auto r = res.render();
    return FCGX_PutStr(r.c_str(), r.size(), m_request.out);
}

int Fcgi_Server_Request_Response::respond_with(std::string const &res) {
    return FCGX_PutStr(res.c_str(), res.size(), m_request.out);
}

std::ostream &Fcgi_Server_Request_Response::log_out() {
    return m_log_stream;
}

char const *
    Fcgi_Server_Request_Response::get_parameter(std::string const &name) const {
    return FCGX_GetParam(name.c_str(), m_request.envp);
}

const std::vector<const char *>
    Fcgi_Server_Request_Response::get_parameters() const {
    std::vector<const char *> res;
    for (size_t i = 0; m_request.envp[i] != nullptr; ++i)
        res.push_back(m_request.envp[i]);
    return res;
}

std::shared_ptr<Fcgi_Server_Request_Response>
    Fcgi_Server_Request_Response::get() {
    return shared_from_this();
}
