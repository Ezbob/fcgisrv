
#pragma once

#include <memory>
#include <thread>
#include "fcgisrv/basic_acceptor.hpp"
#include "fcgisrv/basic_scheduler.hpp"
#include "fcgisrv/fcgi_server_request_response.hpp"
#include "fcgisrv/default_dispatcher.hpp"
#include "fcgiapp.h"

namespace fcgisrv {

    class FcgiAcceptor : public BasicAcceptor {
        BasicDispatcher &m_dispatcher;
        BasicScheduler &m_scheduler;

        std::unique_ptr<std::thread> m_accept_thread;

        void start_accepting();
    public:
        FcgiAcceptor(BasicDispatcher &dispatch, BasicScheduler &multi);

        void start() override;
    };
};
