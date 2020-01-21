
#pragma once

namespace fcgisrv {

    struct BasicAcceptor {
        virtual ~BasicAcceptor() = default;
        virtual void start() = 0;
    };

}; // namespace fcgisrv
