
#include "not_found_handler.hpp"

using namespace fcgisrv;

void Not_Found_Handler::handle(
    std::shared_ptr<fcgisrv::IServer_Request_Response> req) {
    req->respond_with(
        "HTTP/1.1 404 Not Found\r\n"
        "Status: 404 Not Found\r\n"
        "Content-type: text/html\r\n"
        "\r\n"
        "<html>"
        "<head><title>404 Not Found</title><meta charset=\"UTF-8\"></head>"
        "<body><h1>404 Not found</h1></body>"
        "</html>\r\n");
}
