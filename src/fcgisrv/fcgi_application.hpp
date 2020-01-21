
#pragma once

#include <memory>
#include <thread>
#include "fcgisrv/basic_acceptor.hpp"
#include "fcgisrv/basic_scheduler.hpp"
#include "fcgisrv/basic_authenticator.hpp"
#include "fcgisrv/basic_dispatcher.hpp"
#include "fcgisrv/default_authenticator.hpp"
#include "fcgisrv/default_dispatcher.hpp"
#include "fcgisrv/fcgi_acceptor.hpp"

namespace fcgisrv {
    class FcgiApplication {
    private:
        template<typename T>
        using Ptr = std::unique_ptr<T>;

        Ptr<BasicScheduler> m_async_scheduler;
        Ptr<BasicAuthenticator> m_authenticator;
        Ptr<BasicDispatcher> m_dispatcher;
        Ptr<BasicAcceptor> m_acceptor;

    public:
        FcgiApplication(
            std::unique_ptr<BasicScheduler>,
            std::unique_ptr<BasicAuthenticator> = std::unique_ptr<BasicAuthenticator>(),
            std::unique_ptr<BasicDispatcher> = std::unique_ptr<BasicDispatcher>(),
            std::unique_ptr<BasicAcceptor> = std::unique_ptr<BasicAcceptor>()
        );

        void add_get(std::string, std::shared_ptr<BasicHandler>);
        void add_post(std::string, std::shared_ptr<BasicHandler>);
        void add_options(std::string, std::shared_ptr<BasicHandler>);
        void add_patch(std::string, std::shared_ptr<BasicHandler>);
        void add_put(std::string, std::shared_ptr<BasicHandler>);
        void add_delete(std::string, std::shared_ptr<BasicHandler>);

        void start_nonblock();
    };
};
