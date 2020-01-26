
#pragma once

#include "iserver_request_response.hpp"
#include <memory>

namespace fcgisrv {

    struct IHandler {
        virtual ~IHandler() = default;
        virtual void
            handle(std::shared_ptr<IServerRequestResponse> request) = 0;
    };

};