
#pragma once

#include "fcgisrv/basic_handler.hpp"
#include "fcgisrv/basic_server_request_response.hpp"
#include <memory>

namespace fcgisrv {

    struct InternalServerErrorHandler : public BasicHandler {
        void handle(std::shared_ptr<fcgisrv::BasicServerRequestResponse>) override;
    };

}; // namespace fcgisrv
