
#pragma once

#include "ihandler.hpp"
#include "iserver_request_response.hpp"
#include <memory>

namespace fcgisrv {

    struct UnauthorizedHandler: public IHandler {
        void handle(
            std::shared_ptr<fcgisrv::IServerRequestResponse> req) override;
    };

}; // namespace fcgisrv
