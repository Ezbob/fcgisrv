
#include "error_handler_template.hpp"
#include "../http_method.hpp"
#include "../http_helpers.hpp"
#include <string>

using namespace fcgisrv;

Error_Handler_Template::Error_Handler_Template(Http_Error_Code err)
    : m_status(err) {
}

Http_Response Error_Handler_Template::generate_message() {
    Http_Response response;
    std::string code_line =
        m_status.to_string() + " " + m_status.get_translation();

    response.status(m_status);
    response.put_header("Content-type", "text/html");

    response.body() << "<html>"
                       "<head>"
                       "<title>"
                    << code_line
                    << "</title>"
                       "<meta charset=\"UTF-8\">"
                       "</head>"

                       "<body>"
                       "<h1>"
                    << code_line
                    << "</h1>"
                       "</body>"
                       "</html>";

    return response;
}

void Error_Handler_Template::handle(
    std::shared_ptr<IServer_Request_Response> rr) {
    Http_Response html = generate_message();
    rr->respond_with(html);
}
