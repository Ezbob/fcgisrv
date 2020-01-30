
#pragma once

#include <unordered_map>
#include <memory>
#include <string>
#include "default_handlers/internal_server_error_handler.hpp"
#include "default_handlers/method_not_allowed_handler.hpp"
#include "default_handlers/not_found_handler.hpp"
#include "default_handlers/unauthorized_handler.hpp"
#include "http_method.hpp"
#include "iauthenticator.hpp"
#include "idispatcher.hpp"
#include "iserver_request_response.hpp"
#include "ierror_handler_set.hpp"
#include "error_handler_set.hpp"

namespace fcgisrv {

    class Dispatcher: public IDispatcher {
      public:
        Dispatcher(IAuthenticator &auth, IError_Handler_Set &error_set)
            : m_authenticator(auth)
            , m_error_set(error_set) {}

        ~Dispatcher() = default;

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

        IError_Handler_Set &m_error_set;
        IAuthenticator &m_authenticator;
    };
};
