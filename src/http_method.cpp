
#include "http_method.hpp"

using namespace fcgisrv;

HttpMethod fcgisrv::string_to_httpmethod(std::string const &s) {
    if (s == "GET") {
        return HttpMethod::Get;
    } else if (s == "POST") {
        return HttpMethod::Post;
    } else if (s == "PUT") {
        return HttpMethod::Put;
    } else if (s == "PATCH") {
        return HttpMethod::Patch;
    } else if (s == "DELETE") {
        return HttpMethod::Delete;
    } else if (s == "OPTIONS") {
        return HttpMethod::Options;
    } else {
        return HttpMethod::Not_a_method;
    }
}

std::string fcgisrv::httpmethod_to_string(fcgisrv::HttpMethod const &m) {
    if (m == fcgisrv::HttpMethod::Get) {
        return "GET";
    } else if (m == fcgisrv::HttpMethod::Post) {
        return "POST";
    } else if (m == fcgisrv::HttpMethod::Put) {
        return "PUT";
    } else if (m == fcgisrv::HttpMethod::Patch) {
        return "PATCH";
    } else if (m == fcgisrv::HttpMethod::Delete) {
        return "DELETE";
    } else if (m == fcgisrv::HttpMethod::Options) {
        return "OPTIONS";
    } else {
        return "";
    }
}