
#include "generic_error_handler.hpp"
#include "http_method.hpp"
#include "http_helpers.hpp"
#include <string>

using namespace fcgisrv;

Generic_Error_Handler::Generic_Error_Handler(Http_Error_Code err)
    : m_status(err) {
}

Generic_Error_Handler::Generic_Error_Handler(int err)
    : m_status(err) {
}

Http_Response Generic_Error_Handler::generate_message() {
    Http_Response response;
    static std::string code_line =
        m_status.to_string() + " " + m_status.get_translation();

    static std::string body = "<html>"
                              "<head>"
                              "<title>" +
                              code_line +
                              "</title>"
                              "<meta charset=\"UTF-8\">"
                              "</head>"

                              "<body>"
                              "<h1>" +
                              code_line +
                              "</h1>"
                              "</body>"
                              "</html>";

    response.status(m_status);
    response.put_header("Content-type", "text/html");

    response.body() << body;

    return response;
}

void Generic_Error_Handler::handle(Fcgi_Request_Response rr) {
    Http_Response html = generate_message();
    rr->respond_with(html);
}
