
#include "http_method.hpp"

using namespace fcgisrv;

Http_Method fcgisrv::string_to_httpmethod(std::string const &s) {
    if (s == "GET") {
        return Http_Method::Get;
    } else if (s == "POST") {
        return Http_Method::Post;
    } else if (s == "PUT") {
        return Http_Method::Put;
    } else if (s == "PATCH") {
        return Http_Method::Patch;
    } else if (s == "DELETE") {
        return Http_Method::Delete;
    } else if (s == "OPTIONS") {
        return Http_Method::Options;
    } else {
        return Http_Method::Not_a_method;
    }
}

std::string fcgisrv::httpmethod_to_string(fcgisrv::Http_Method const &m) {
    if (m == fcgisrv::Http_Method::Get) {
        return "GET";
    } else if (m == fcgisrv::Http_Method::Post) {
        return "POST";
    } else if (m == fcgisrv::Http_Method::Put) {
        return "PUT";
    } else if (m == fcgisrv::Http_Method::Patch) {
        return "PATCH";
    } else if (m == fcgisrv::Http_Method::Delete) {
        return "DELETE";
    } else if (m == fcgisrv::Http_Method::Options) {
        return "OPTIONS";
    } else {
        return "";
    }
}