
#include "fcgi_application.hpp"
#include "http_method.hpp"

using namespace fcgisrv;

FcgiApplication::FcgiApplication(
    std::unique_ptr<BasicScheduler> sch,
    std::unique_ptr<BasicAuthenticator> auth,
    std::unique_ptr<BasicDispatcher> dispatch,
    std::unique_ptr<BasicAcceptor> acceptor
)
: m_async_scheduler(std::move(sch))
, m_authenticator(auth == nullptr ? Ptr<BasicAuthenticator>(new DefaultAuthenticator()) : std::move(auth) )
, m_dispatcher(dispatch == nullptr ? Ptr<DefaultDispatcher>(new DefaultDispatcher(*m_authenticator)) : std::move(dispatch))
, m_acceptor(acceptor == nullptr ? Ptr<BasicAcceptor>(new FcgiAcceptor(*m_dispatcher, *m_async_scheduler)) : std::move(acceptor))
{}

void FcgiApplication::add_get(std::string uri, std::shared_ptr<BasicHandler> req) {
    m_dispatcher->add_endpoint(uri, HttpMethod::Get, req);
}

void FcgiApplication::add_post(std::string uri, std::shared_ptr<BasicHandler> req) {
    m_dispatcher->add_endpoint(uri, HttpMethod::Post, req);
}

void FcgiApplication::add_options(std::string uri, std::shared_ptr<BasicHandler> req) {
    m_dispatcher->add_endpoint(uri, HttpMethod::Options, req);
}

void FcgiApplication::add_patch(std::string uri, std::shared_ptr<BasicHandler> req) {
    m_dispatcher->add_endpoint(uri, HttpMethod::Patch, req);
}

void FcgiApplication::add_put(std::string uri, std::shared_ptr<BasicHandler> req) {
    m_dispatcher->add_endpoint(uri, HttpMethod::Put, req);
}

void FcgiApplication::add_delete(std::string uri, std::shared_ptr<BasicHandler> req) {
    m_dispatcher->add_endpoint(uri, HttpMethod::Delete, req);
}

void FcgiApplication::start_nonblock() {
    m_acceptor->start();
}
