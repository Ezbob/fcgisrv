
#pragma once

namespace fcgisrv {

    struct IAcceptor {
        virtual ~IAcceptor() = default;
        virtual void start_nonblock() = 0;
        virtual void start_block() = 0;
    };

}; // namespace fcgisrv
