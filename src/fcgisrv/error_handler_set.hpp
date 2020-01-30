
#ifndef _HEADER_FILE_error_handler_set_20200130203339_
#define _HEADER_FILE_error_handler_set_20200130203339_

#include <memory>
#include "ierror_handler_set.hpp"

#include "default_handlers/internal_server_error_handler.hpp"
#include "default_handlers/method_not_allowed_handler.hpp"
#include "default_handlers/not_found_handler.hpp"
#include "default_handlers/unauthorized_handler.hpp"

namespace fcgisrv {

    class Error_Handler_Set : public IError_Handler_Set {
        Ptr_t m_handler_401 = std::make_shared<Unauthorized_Handler>();
        Ptr_t m_handler_404 = std::make_shared<Not_Found_Handler>();
        Ptr_t m_handler_405 = std::make_shared<Method_Not_Allowed_Handler>();
        Ptr_t m_handler_500 = std::make_shared<Internal_Server_Error_Handler>();
    public:
        std::shared_ptr<IHandler> error_401() override;
        std::shared_ptr<IHandler> error_404() override;
        std::shared_ptr<IHandler> error_405() override;
        std::shared_ptr<IHandler> error_500() override;
    };
} // namespace fcgisrv

#endif