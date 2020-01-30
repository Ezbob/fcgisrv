
#pragma once

#include <memory>
#include "../ihandler.hpp"
#include "../iserver_request_response.hpp"

namespace fcgisrv {

    struct Unauthorized_Handler: public IHandler {
        void handle(
            std::shared_ptr<fcgisrv::IServer_Request_Response> req) override;
    };

}; // namespace fcgisrv
