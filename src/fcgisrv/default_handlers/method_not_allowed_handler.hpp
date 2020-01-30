
#pragma once

#include <memory>

#include "../ihandler.hpp"
#include "../iserver_request_response.hpp"

namespace fcgisrv {

    struct Method_Not_Allowed_Handler: public IHandler {
        void
            handle(std::shared_ptr<fcgisrv::IServer_Request_Response>) override;
    };

}; // namespace fcgisrv
