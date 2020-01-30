
#ifndef _HEADER_FILE_method_20200113205822_
#define _HEADER_FILE_method_20200113205822_

#include <string>

namespace fcgisrv {
    enum class Http_Method {
        Get,
        Post,
        Put,
        Patch,
        Delete,
        Options,
        Not_a_method
    };

    Http_Method string_to_httpmethod(std::string const &s);
    std::string httpmethod_to_string(Http_Method const &m);
};

#endif