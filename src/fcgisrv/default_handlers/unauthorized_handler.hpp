
#pragma once

#include "fcgisrv/basic_handler.hpp"
#include "fcgisrv/basic_server_request_response.hpp"
#include <memory>

namespace fcgisrv {

    struct UnauthorizedHandler : public BasicHandler {
        void handle(std::shared_ptr<fcgisrv::BasicServerRequestResponse> req) override;
    };

}; // namespace fcgisrv
