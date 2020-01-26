
#include "default_handlers/method_not_allowed_handler.hpp"

using namespace fcgisrv;

void MethodNotAllowedHandler::handle(
    std::shared_ptr<fcgisrv::IServerRequestResponse> req) {
    req->respond_with("HTTP/1.1 405 Method Not Allowed\r\n"
                      "Status: 405 Method Not Allowed\r\n"
                      "Content-type: text/html\r\n"
                      "\r\n"
                      "<html>"
                      "<head><title>405 Method Not Allowed</title><meta "
                      "charset=\"UTF-8\"></head>"
                      "<body><h1>405 Method Not Allowed</h1></body>"
                      "</html>\r\n");
}
