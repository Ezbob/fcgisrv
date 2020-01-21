
#ifndef _HEADER_FILE_method_20200113205822_
#define _HEADER_FILE_method_20200113205822_

#include <string>

namespace fcgisrv {
    enum class HttpMethod {
        Get,
        Post,
        Put,
        Patch,
        Delete,
        Options,
        Not_a_method
    };

    HttpMethod string_to_httpmethod(std::string const& s);
    std::string httpmethod_to_string(HttpMethod const& m);
};

#endif