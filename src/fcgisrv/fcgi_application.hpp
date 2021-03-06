
#pragma once

#include <memory>

#include "iacceptor.hpp"
#include "iapplication.hpp"
#include "iauthenticator.hpp"
#include "idispatcher.hpp"
#include "ischeduler.hpp"
#include "ierror_handler_provider.hpp"

namespace fcgisrv {
    class Fcgi_Application: public IApplication {
      private:
        template<typename T>
        using RC_t = std::shared_ptr<T>;

        RC_t<IScheduler> m_async_scheduler;
        RC_t<IAuthenticator> m_authenticator;
        RC_t<IError_Handler_Provider> m_errors;
        RC_t<IDispatcher> m_dispatcher;
        RC_t<IAcceptor> m_acceptor;

      public:
        Fcgi_Application(
            std::shared_ptr<IScheduler>,
            std::shared_ptr<IAuthenticator> = RC_t<IAuthenticator>(),
            std::shared_ptr<IError_Handler_Provider> =
                RC_t<IError_Handler_Provider>(),
            std::shared_ptr<IDispatcher> = RC_t<IDispatcher>(),
            std::shared_ptr<IAcceptor> = RC_t<IAcceptor>());

        void add_get(std::string, std::shared_ptr<IHandler>);
        void add_post(std::string, std::shared_ptr<IHandler>);
        void add_options(std::string, std::shared_ptr<IHandler>);
        void add_patch(std::string, std::shared_ptr<IHandler>);
        void add_put(std::string, std::shared_ptr<IHandler>);
        void add_delete(std::string, std::shared_ptr<IHandler>);

        void start_nonblock() override;
        void start_block() override;
    };
};
