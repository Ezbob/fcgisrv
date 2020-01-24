
#pragma once

#include "fcgisrv/http_method.hpp"
#include "fcgisrv/default_handlers/internal_server_error_handler.hpp"
#include "fcgisrv/default_handlers/method_not_allowed_handler.hpp"
#include "fcgisrv/default_handlers/not_found_handler.hpp"
#include "fcgisrv/default_handlers/unauthorized_handler.hpp"

#include "fcgisrv/idispatcher.hpp"
#include "fcgisrv/iserver_request_response.hpp"
#include "fcgisrv/iauthenticator.hpp"

#include <unordered_map>
#include <memory>
#include <string>

namespace fcgisrv {

    class DefaultDispatcher: public IDispatcher {
      public:
        DefaultDispatcher(IAuthenticator &auth)
            : m_authenticator(auth) {}

        ~DefaultDispatcher() = default;

        void dispatch(std::shared_ptr<IServerRequestResponse>) override;

        void add_endpoint(std::string uri, HttpMethod,
                          std::shared_ptr<IHandler>) override;

      private:
        std::shared_ptr<IHandler>
            select(std::shared_ptr<IServerRequestResponse> req_ptr) const;

        std::string build_uri(const char *raw) const;
        void add_end_slash(std::string &uri) const;

        using HandlerMap_t =
            std::unordered_map<HttpMethod, std::shared_ptr<IHandler>>;
        std::unordered_map<std::string, HandlerMap_t> m_dispatch_matrix;

        std::shared_ptr<IHandler> m_handler_500 =
            std::make_shared<InternalServerErrorHandler>();
        std::shared_ptr<IHandler> m_handler_404 =
            std::make_shared<NotFoundHandler>();
        std::shared_ptr<IHandler> m_handler_401 =
            std::make_shared<UnauthorizedHandler>();
        std::shared_ptr<IHandler> m_handler_405 =
            std::make_shared<MethodNotAllowedHandler>();

        IAuthenticator &m_authenticator;
    };
};
