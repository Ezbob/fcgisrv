
#pragma once

#include <memory>
#include <string>

#include "http_method.hpp"
#include "ihandler.hpp"
#include "iserver_request_response.hpp"

namespace fcgisrv {

    struct IDispatcher {
        virtual ~IDispatcher() = default;
        virtual void
            dispatch(std::shared_ptr<IServer_Request_Response> req_ptr) = 0;
        virtual void add_endpoint(std::string, Http_Method,
                                  std::shared_ptr<IHandler>) = 0;
    };

}; // namespace fcgisrv
