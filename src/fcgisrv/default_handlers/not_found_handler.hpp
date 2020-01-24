
#pragma once

#include <memory>
#include "fcgisrv/ihandler.hpp"
#include "fcgisrv/iserver_request_response.hpp"

namespace fcgisrv {

    struct NotFoundHandler: public IHandler {
        void handle(std::shared_ptr<fcgisrv::IServerRequestResponse>) override;
    };

}; // namespace fcgisrv
