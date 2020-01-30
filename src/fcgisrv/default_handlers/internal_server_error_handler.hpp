
#pragma once

#include <memory>
#include "../IHandler.hpp"
#include "../IServer_Request_Response.hpp"

namespace fcgisrv {

    struct Internal_Server_Error_Handler: public IHandler {
        void
            handle(std::shared_ptr<fcgisrv::IServer_Request_Response>) override;
    };

}; // namespace fcgisrv
