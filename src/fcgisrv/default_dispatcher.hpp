
#pragma once

#include <unordered_map>
#include <memory>
#include <string>
#include "default_handlers/Internal_Server_Error_Handler.hpp"
#include "default_handlers/Method_Not_Allowed_Handler.hpp"
#include "default_handlers/Not_Found_Handler.hpp"
#include "default_handlers/Unauthorized_Handler.hpp"
#include "Http_Method.hpp"
#include "IAuthenticator.hpp"
#include "IDispatcher.hpp"
#include "IServer_Request_Response.hpp"

namespace fcgisrv {

    class Default_Dispatcher: public IDispatcher {
      public:
        Default_Dispatcher(IAuthenticator &auth)
            : m_authenticator(auth) {}

        ~Default_Dispatcher() = default;

        void dispatch(std::shared_ptr<IServer_Request_Response>) override;

        void add_endpoint(std::string, Http_Method,
                          std::shared_ptr<IHandler>) override;

      private:
        std::shared_ptr<IHandler>
            select(std::shared_ptr<IServer_Request_Response> req_ptr) const;

        std::string build_uri(const char *raw) const;
        void add_end_slash(std::string &uri) const;

        using HandlerMap_t =
            std::unordered_map<Http_Method, std::shared_ptr<IHandler>>;
        std::unordered_map<std::string, HandlerMap_t> m_dispatch_matrix;

        std::shared_ptr<IHandler> m_handler_500 =
            std::make_shared<Internal_Server_Error_Handler>();
        std::shared_ptr<IHandler> m_handler_404 =
            std::make_shared<Not_Found_Handler>();
        std::shared_ptr<IHandler> m_handler_401 =
            std::make_shared<Unauthorized_Handler>();
        std::shared_ptr<IHandler> m_handler_405 =
            std::make_shared<Method_Not_Allowed_Handler>();

        IAuthenticator &m_authenticator;
    };
};
