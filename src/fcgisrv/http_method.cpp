
#include "http_method.hpp"

using namespace fcgisrv;

Http_Method::Http_Method(int b) : m_value(b) {}

std::string Http_Method::to_string() const {
    switch (m_value) {
        case fcgisrv::Http_Method::Get:
            return "GET";
        case fcgisrv::Http_Method::Post:
            return "POST";
        case fcgisrv::Http_Method::Put:
            return "PUT";
        case fcgisrv::Http_Method::Patch:
            return "PATCH";
        case fcgisrv::Http_Method::Delete:
            return "DELETE";
        case fcgisrv::Http_Method::Options:
            return "OPTIONS";
    }
    return "";
}

Http_Method Http_Method::from_string(std::string const &s) {
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

bool Http_Method::operator==(Http_Method const &other) {
    return other.m_value == m_value;
}

bool Http_Method::operator!=(Http_Method const &other) {
    return other.m_value != m_value;
}
