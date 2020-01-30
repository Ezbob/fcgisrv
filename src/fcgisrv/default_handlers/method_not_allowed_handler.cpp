
#include "Method_Not_Allowed_Handler.hpp"

using namespace fcgisrv;

void Method_Not_Allowed_Handler::handle(
    std::shared_ptr<fcgisrv::IServer_Request_Response> req) {
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
