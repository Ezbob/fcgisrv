
#pragma once

#include <memory>
#include "fcgisrv/basic_handler.hpp"
#include "fcgisrv/basic_server_request_response.hpp"

namespace fcgisrv {

    struct NotFoundHandler : public BasicHandler {
        void handle(std::shared_ptr<fcgisrv::BasicServerRequestResponse>) override;
    };

}; // namespace fcgisrv
