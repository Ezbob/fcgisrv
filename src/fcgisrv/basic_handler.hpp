
#pragma once

#include "fcgisrv/basic_server_request_response.hpp"
#include <memory>

namespace fcgisrv {

    struct BasicHandler {
        virtual ~BasicHandler() = default;
        virtual void handle(std::shared_ptr<BasicServerRequestResponse> request) = 0;
    };

};