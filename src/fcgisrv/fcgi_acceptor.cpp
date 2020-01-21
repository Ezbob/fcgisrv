
#include "fcgisrv/fcgi_acceptor.hpp"

using namespace fcgisrv;

FcgiAcceptor::FcgiAcceptor(BasicDispatcher &dispatch, BasicScheduler &sch)
    : m_dispatcher(dispatch)
    , m_scheduler(sch) {
    FCGX_Init();
}

void FcgiAcceptor::start_accepting() {
    while (true) {
        auto request = std::make_shared<FcgiServerRequestResponse>();

        if ( request->accept() ) {
            m_scheduler.schedule_task([this, request] {
                m_dispatcher.dispatch(request);
            });
        }
    }
}

void FcgiAcceptor::start() {
    if (!m_accept_thread) {
        m_accept_thread = std::unique_ptr<std::thread>(new std::thread([this] {
            start_accepting();
        }));
    }
}
