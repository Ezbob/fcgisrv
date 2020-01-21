
#pragma once

#include <functional>

namespace fcgisrv {

    struct BasicScheduler {
        virtual ~BasicScheduler() = default;
        virtual void schedule_task(std::function<void()> const&) = 0;
    };

}; // namespace fcgisrv
