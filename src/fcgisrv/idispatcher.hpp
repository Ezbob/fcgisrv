
#pragma once

#include <memory>
#include <string>

#include "Http_Method.hpp"
#include "IHandler.hpp"
#include "IServer_Request_Response.hpp"

namespace fcgisrv {

    struct IDispatcher {
        virtual ~IDispatcher() = default;
        virtual void
            dispatch(std::shared_ptr<IServer_Request_Response> req_ptr) = 0;
        virtual void add_endpoint(std::string, Http_Method,
                                  std::shared_ptr<IHandler>) = 0;
    };

}; // namespace fcgisrv
