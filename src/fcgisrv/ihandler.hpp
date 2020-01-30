
#pragma once

#include <memory>
#include "iserver_request_response.hpp"

namespace fcgisrv {

    struct IHandler {
        virtual ~IHandler() = default;
        virtual void
            handle(std::shared_ptr<IServer_Request_Response> request) = 0;
    };

};