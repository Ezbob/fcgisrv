
#pragma once

namespace fcgisrv {

    struct IAcceptor {
        virtual ~IAcceptor() = default;
        virtual void start() = 0;
    };

}; // namespace fcgisrv
