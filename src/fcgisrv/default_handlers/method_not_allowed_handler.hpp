
#pragma once

#include <memory>
#include "fcgisrv/iserver_request_response.hpp"
#include "fcgisrv/ihandler.hpp"

namespace fcgisrv {

    struct MethodNotAllowedHandler : public IHandler {
        void handle(std::shared_ptr<fcgisrv::IServerRequestResponse>) override;
    };

}; // namespace fcgisrv
