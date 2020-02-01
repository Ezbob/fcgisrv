
#pragma once

#include <memory>
#include "http_error_code.hpp"
#include "ihandler.hpp"

namespace fcgisrv {

    struct IError_Handler_Provider {
        virtual ~IError_Handler_Provider() = default;

        virtual std::shared_ptr<IHandler>
            get_error(Http_Error_Code const &) = 0;
        virtual std::shared_ptr<IHandler> get_error(int) = 0;
    };

}; // namespace fcgisrv
