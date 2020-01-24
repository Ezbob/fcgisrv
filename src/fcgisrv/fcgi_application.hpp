
#pragma once

#include <memory>
#include <thread>
#include "fcgisrv/iacceptor.hpp"
#include "fcgisrv/ischeduler.hpp"
#include "fcgisrv/iauthenticator.hpp"
#include "fcgisrv/idispatcher.hpp"
#include "fcgisrv/default_authenticator.hpp"
#include "fcgisrv/default_dispatcher.hpp"
#include "fcgisrv/fcgi_acceptor.hpp"

namespace fcgisrv {
    class FcgiApplication {
    private:
        template<typename T>
        using Ptr = std::unique_ptr<T>;

        Ptr<IScheduler> m_async_scheduler;
        Ptr<IAuthenticator> m_authenticator;
        Ptr<IDispatcher> m_dispatcher;
        Ptr<IAcceptor> m_acceptor;

    public:
        FcgiApplication(
            std::unique_ptr<IScheduler>,
            std::unique_ptr<IAuthenticator> = std::unique_ptr<IAuthenticator>(),
            std::unique_ptr<IDispatcher> = std::unique_ptr<IDispatcher>(),
            std::unique_ptr<IAcceptor> = std::unique_ptr<IAcceptor>()
        );

        void add_get(std::string, std::shared_ptr<IHandler>);
        void add_post(std::string, std::shared_ptr<IHandler>);
        void add_options(std::string, std::shared_ptr<IHandler>);
        void add_patch(std::string, std::shared_ptr<IHandler>);
        void add_put(std::string, std::shared_ptr<IHandler>);
        void add_delete(std::string, std::shared_ptr<IHandler>);

        void start_nonblock();
    };
};
