
#include "fcgi_application.hpp"
#include "http_method.hpp"

using namespace fcgisrv;

FcgiApplication::FcgiApplication(RC_t<IScheduler> sch,
                                 RC_t<IAuthenticator> auth,
                                 RC_t<IDispatcher> dispatch,
                                 RC_t<IAcceptor> acceptor)
    : m_async_scheduler(sch)
    , m_authenticator(!auth ? std::make_shared<DefaultAuthenticator>() : auth)
    , m_dispatcher(!dispatch ? std::make_shared<DefaultDispatcher>(*m_authenticator) : dispatch)
    , m_acceptor(!acceptor ? std::make_shared<FcgiAcceptor>(*m_dispatcher, *m_async_scheduler) : acceptor) {}

void FcgiApplication::add_get(std::string uri, std::shared_ptr<IHandler> req) {
    m_dispatcher->add_endpoint(uri, HttpMethod::Get, req);
}

void FcgiApplication::add_post(std::string uri, std::shared_ptr<IHandler> req) {
    m_dispatcher->add_endpoint(uri, HttpMethod::Post, req);
}

void FcgiApplication::add_options(std::string uri,
                                  std::shared_ptr<IHandler> req) {
    m_dispatcher->add_endpoint(uri, HttpMethod::Options, req);
}

void FcgiApplication::add_patch(std::string uri,
                                std::shared_ptr<IHandler> req) {
    m_dispatcher->add_endpoint(uri, HttpMethod::Patch, req);
}

void FcgiApplication::add_put(std::string uri, std::shared_ptr<IHandler> req) {
    m_dispatcher->add_endpoint(uri, HttpMethod::Put, req);
}

void FcgiApplication::add_delete(std::string uri,
                                 std::shared_ptr<IHandler> req) {
    m_dispatcher->add_endpoint(uri, HttpMethod::Delete, req);
}

void FcgiApplication::start_nonblock() {
    m_acceptor->start();
}
