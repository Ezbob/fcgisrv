
#pragma once

#include <unordered_map>
#include <memory>
#include <string>
#include "http_method.hpp"
#include "iauthenticator.hpp"
#include "idispatcher.hpp"
#include "ierror_handler_provider.hpp"
#include "error_handler_set.hpp"

namespace fcgisrv {

    class Dispatcher: public IDispatcher {
      public:
        Dispatcher(IAuthenticator &auth, IError_Handler_Provider &error_set)
            : m_authenticator(auth)
            , m_error_set(error_set) {
        }

        ~Dispatcher() = default;

        void dispatch(Fcgi_Request_Response) override;

        void add_endpoint(std::string, Http_Method,
                          std::shared_ptr<IHandler>) override;

      private:
        std::shared_ptr<IHandler> select(Fcgi_Request_Response req_ptr) const;

        using HandlerMap_t =
            std::unordered_map<Http_Method, std::shared_ptr<IHandler>>;
        std::unordered_map<std::string, HandlerMap_t> m_dispatch_matrix;

        IAuthenticator &m_authenticator;
        IError_Handler_Provider &m_error_set;
    };
};
