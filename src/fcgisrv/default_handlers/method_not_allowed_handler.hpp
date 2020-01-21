
#pragma once

#include <memory>
#include "fcgisrv/basic_server_request_response.hpp"
#include "fcgisrv/basic_handler.hpp"

namespace fcgisrv {

    struct MethodNotAllowedHandler : public BasicHandler {
        void handle(std::shared_ptr<fcgisrv::BasicServerRequestResponse>) override;
    };

}; // namespace fcgisrv
