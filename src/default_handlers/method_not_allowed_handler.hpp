
#pragma once

#include <memory>
#include "iserver_request_response.hpp"
#include "ihandler.hpp"

namespace fcgisrv {

    struct MethodNotAllowedHandler: public IHandler {
        void handle(std::shared_ptr<fcgisrv::IServerRequestResponse>) override;
    };

}; // namespace fcgisrv
