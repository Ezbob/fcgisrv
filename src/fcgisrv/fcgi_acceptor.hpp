
#pragma once

#include <memory>
#include <thread>

#include "default_dispatcher.hpp"
#include "fcgiapp.h"
#include "fcgi_server_request_response.hpp"
#include "iacceptor.hpp"
#include "ischeduler.hpp"

namespace fcgisrv {

    class Fcgi_Acceptor: public IAcceptor {
        IDispatcher &m_dispatcher;
        IScheduler &m_scheduler;

        std::unique_ptr<std::thread> m_accept_thread;

        void start_accepting();

      public:
        Fcgi_Acceptor(IDispatcher &dispatch, IScheduler &multi);

        void start_nonblock() override;
        void start_block() override;
    };
};
