#include "http_response.hpp"
#include "http_helpers.hpp"
#include <string>

using namespace fcgisrv;

std::string Http_Response::render() {
    std::stringstream res;
    std::string translated = m_error_code.get_translation();

    res << "HTTP/1.1 " << m_error_code.to_int() << " " << translated
        << HTTP_LINE_END;
    res << "Status: " << m_error_code.to_int() << " " << translated
        << HTTP_LINE_END;
    res << m_header.str();
    res << HTTP_LINE_END;
    res << m_body.str();

    return res.str();
}

void Http_Response::put_header(std::string const &raw) {
    m_header << (raw + HTTP_LINE_END);
}

void Http_Response::put_header(std::string const &name,
                               std::string const &value) {
    m_header << (name + ": " + value + HTTP_LINE_END);
}

void Http_Response::status(int code) {
    m_error_code = code;
}

void Http_Response::status(Http_Error_Code const &code) {
    m_error_code = code.to_int();
}

Http_Error_Code Http_Response::status() const {
    return m_error_code;
}

std::ostream &Http_Response::body() {
    return m_body;
}