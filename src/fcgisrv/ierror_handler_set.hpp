
#pragma once

#include <memory>
#include "ihandler.hpp"

namespace fcgisrv {

    struct IError_Handler_Set {
    protected:
        using Ptr_t = std::shared_ptr<IHandler>;
    public:
        virtual ~IError_Handler_Set() = default;

        virtual std::shared_ptr<IHandler> error_401() = 0;
        virtual std::shared_ptr<IHandler> error_404() = 0;
        virtual std::shared_ptr<IHandler> error_405() = 0;
        virtual std::shared_ptr<IHandler> error_500() = 0;
    };

}; // namespace fcgisrv
