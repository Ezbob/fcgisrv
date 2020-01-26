
#include "default_handlers/internal_server_error_handler.hpp"

using namespace fcgisrv;

void InternalServerErrorHandler::handle(
    std::shared_ptr<fcgisrv::IServerRequestResponse> req) {
    req->respond_with("HTTP/1.1 500 Internal Server Error\r\n"
                      "Status: 500 Internal Server Error\r\n"
                      "Content-type: text/html\r\n"
                      "\r\n"
                      "<html>"
                      "<head><title>500 Internal Server Error</title><meta "
                      "charset=\"UTF-8\"></head>"
                      "<body><h1>500 Internal Server Error</h1></body>"
                      "</html>\r\n");
}
