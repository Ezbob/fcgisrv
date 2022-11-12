#include "handlers/current_time_handler.hpp"

#include <memory>

using namespace fcgitest;

void Current_Time_Handler::handle(fcgisrv::Fcgi_Request_Response rr) {

    fcgisrv::Json_Response json_resp;

    auto t = std::time(nullptr);
    char timestr[100];
    std::strftime(timestr, sizeof(timestr), "%c %Z", std::localtime(&t));

    json_resp.body() << "{\"localtime\": \"" << std::string(timestr) << "\"}";

    rr->respond_with(json_resp);
}