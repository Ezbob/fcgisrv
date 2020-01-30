
#include "Unauthorized_Handler.hpp"

using namespace fcgisrv;

void Unauthorized_Handler::handle(
    std::shared_ptr<fcgisrv::IServer_Request_Response> req) {
    req->respond_with(
        "HTTP/1.1 401 Unauthorized\r\n"
        "Status: 401 Unauthorized\r\n"
        "Content-type: text/html\r\n"
        "\r\n"
        "<html>"
        "<head><title>401 Unauthorized</title><meta charset=\"UTF-8\"></head>"
        "<body><h1>401 Unauthorized</h1></body>"
        "</html>\r\n");
}
