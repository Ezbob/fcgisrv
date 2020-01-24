
#pragma once

#include <memory>
#include "iserver_request_response.hpp"

namespace fcgisrv {

    struct IAuthenticator {
        virtual ~IAuthenticator() = default;
        virtual bool
            is_valid(std::shared_ptr<IServerRequestResponse>) = 0;
    };

}; // namespace fcgisrv
