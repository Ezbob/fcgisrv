
#pragma once

#include <functional>

namespace fcgisrv {

    struct IScheduler {
        virtual ~IScheduler() = default;
        virtual void schedule_task(std::function<void()> const &) = 0;
    };

}; // namespace fcgisrv
