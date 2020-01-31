
#include "fcgi_acceptor.hpp"

using namespace fcgisrv;

Fcgi_Acceptor::Fcgi_Acceptor(IDispatcher &dispatch, IScheduler &sch)
    : m_dispatcher(dispatch)
    , m_scheduler(sch) {
    FCGX_Init();
}

void Fcgi_Acceptor::start_accepting() {
    while (true) {
        auto request = std::make_shared<Fcgi_Server_Request_Response>();

        if (request->accept()) {
            m_scheduler.schedule_task(
                [this, request] { m_dispatcher.dispatch(request); });
        }
    }
}

void Fcgi_Acceptor::start_nonblock() {
    if (!m_accept_thread) {
        m_accept_thread = std::unique_ptr<std::thread>(
            new std::thread([this] { start_accepting(); }));
    }
}

void Fcgi_Acceptor::start_block() {
    start_accepting();
}
