
#pragma once

#include <memory>
#include "fcgi_server_request_response.hpp"

namespace fcgisrv {

    struct IHandler {
        virtual ~IHandler() = default;
        virtual void handle(Fcgi_Request_Response request) = 0;
    };

};