
#pragma once

#include <memory>

#include "fcgi_server_request_response.hpp"

namespace fcgisrv {

    struct IAuthenticator {
        virtual ~IAuthenticator() = default;
        virtual bool is_valid(Fcgi_Request_Response) = 0;
    };

}; // namespace fcgisrv
