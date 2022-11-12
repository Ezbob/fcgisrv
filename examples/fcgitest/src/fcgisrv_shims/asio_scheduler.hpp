
#pragma once

#include "fcgisrv/fcgisrv.hpp"
#include "asio.hpp"

namespace fcgisrv {

    class Asio_Scheduler: public IScheduler {
        asio::io_context &m_io_ctx;

      public:
        Asio_Scheduler(asio::io_context &io_ctx)
            : m_io_ctx(io_ctx) {}

        void schedule_task(std::function<void()> const &task) override;
    };

}; // namespace fcgisrv
