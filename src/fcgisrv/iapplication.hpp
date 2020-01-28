
#pragma once

namespace fcgisrv {

    struct IApplication {
        virtual ~IApplication() = default;
        virtual void start_nonblock() = 0;
        virtual void start_block() = 0;
    };

}; // namespace fcgisrv
