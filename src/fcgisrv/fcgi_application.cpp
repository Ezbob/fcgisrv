
#include "fcgi_application.hpp"

#include <memory>
#include "http_method.hpp"
#include "authenticator.hpp"
#include "dispatcher.hpp"
#include "fcgi_acceptor.hpp"

using namespace fcgisrv;

Fcgi_Application::Fcgi_Application(RC_t<IScheduler> sch,
                                   RC_t<IAuthenticator> auth,
                                   RC_t<IDispatcher> dispatch,
                                   RC_t<IAcceptor> acceptor,
                                   RC_t<IError_Handler_Set> error_set)
    : m_async_scheduler(sch)
    , m_authenticator(!auth ? std::make_shared<Authenticator>() : auth)
    , m_errors(!error_set ? std::make_shared<Error_Handler_Set>() : error_set)
    , m_dispatcher(!dispatch ? std::make_shared<Dispatcher>(*m_authenticator, *m_errors)
                             : dispatch)
    , m_acceptor(!acceptor ? std::make_shared<Fcgi_Acceptor>(*m_dispatcher,
                                                             *m_async_scheduler)
                           : acceptor) {}

void Fcgi_Application::add_get(std::string uri, std::shared_ptr<IHandler> req) {
    m_dispatcher->add_endpoint(uri, Http_Method::Get, req);
}

void Fcgi_Application::add_post(std::string uri,
                                std::shared_ptr<IHandler> req) {
    m_dispatcher->add_endpoint(uri, Http_Method::Post, req);
}

void Fcgi_Application::add_options(std::string uri,
                                   std::shared_ptr<IHandler> req) {
    m_dispatcher->add_endpoint(uri, Http_Method::Options, req);
}

void Fcgi_Application::add_patch(std::string uri,
                                 std::shared_ptr<IHandler> req) {
    m_dispatcher->add_endpoint(uri, Http_Method::Patch, req);
}

void Fcgi_Application::add_put(std::string uri, std::shared_ptr<IHandler> req) {
    m_dispatcher->add_endpoint(uri, Http_Method::Put, req);
}

void Fcgi_Application::add_delete(std::string uri,
                                  std::shared_ptr<IHandler> req) {
    m_dispatcher->add_endpoint(uri, Http_Method::Delete, req);
}

void Fcgi_Application::start_nonblock() {
    m_acceptor->start_nonblock();
}

void Fcgi_Application::start_block() {
    m_acceptor->start_block();
}
