
#pragma once

#include <memory>

#include "IServer_Request_Response.hpp"

namespace fcgisrv {

    struct IAuthenticator {
        virtual ~IAuthenticator() = default;
        virtual bool is_valid(std::shared_ptr<IServer_Request_Response>) = 0;
    };

}; // namespace fcgisrv
