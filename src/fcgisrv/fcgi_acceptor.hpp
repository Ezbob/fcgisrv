
#pragma once

#include <memory>
#include <thread>
#include "fcgisrv/iacceptor.hpp"
#include "fcgisrv/ischeduler.hpp"
#include "fcgisrv/fcgi_server_request_response.hpp"
#include "fcgisrv/default_dispatcher.hpp"
#include "fcgiapp.h"

namespace fcgisrv {

    class FcgiAcceptor : public IAcceptor {
        IDispatcher &m_dispatcher;
        IScheduler &m_scheduler;

        std::unique_ptr<std::thread> m_accept_thread;

        void start_accepting();
    public:
        FcgiAcceptor(IDispatcher &dispatch, IScheduler &multi);

        void start() override;
    };
};
