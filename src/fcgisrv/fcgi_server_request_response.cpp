
#include "fcgisrv/fcgi_server_request_response.hpp"
#include "fcgisrv/iformatted_response.hpp"

using namespace fcgisrv;

FcgiServerRequestResponse::FcgiServerRequestResponse() : m_is_accepted(false) {
    FCGX_InitRequest(&m_request, 0, 0);
}

FcgiServerRequestResponse::~FcgiServerRequestResponse() {
    if (m_is_accepted) {
        FCGX_Finish_r(&m_request);
    }
}

bool FcgiServerRequestResponse::accept() {
    m_is_accepted = (FCGX_Accept_r(&m_request) == 0);
    return m_is_accepted;
}

bool FcgiServerRequestResponse::is_accepted() {
    return m_is_accepted;
}

int FcgiServerRequestResponse::respond_with(IFormattedResponse &res) {
    auto r = res.render();
    return FCGX_PutStr(r.c_str(), r.size(), m_request.out);
}

int FcgiServerRequestResponse::respond_with(std::string const &res) {
    return FCGX_PutStr(res.c_str(), res.size(), m_request.out);
}

int FcgiServerRequestResponse::log(std::string &res) {
    return FCGX_PutStr(res.c_str(), res.size(), m_request.err);
}

char const *FcgiServerRequestResponse::get_parameter(std::string const &name) const {
    return FCGX_GetParam(name.c_str(), m_request.envp);
}

const std::vector<const char *> FcgiServerRequestResponse::get_parameters() const {
    std::vector<const char *> res;
    for (size_t i = 0; m_request.envp[i] != nullptr; ++i) 
        res.push_back(m_request.envp[i]);
    return res;
}

std::shared_ptr<FcgiServerRequestResponse> FcgiServerRequestResponse::get() {
    return shared_from_this();
}
