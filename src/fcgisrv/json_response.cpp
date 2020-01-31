
#include "json_response.hpp"

using namespace fcgisrv;

std::string Json_Response::render() {
    put_header("Content-Type", "application/json");
    return Http_Response::render();
}
