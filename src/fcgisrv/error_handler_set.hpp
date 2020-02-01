
#ifndef _HEADER_FILE_error_handler_set_20200130203339_
#define _HEADER_FILE_error_handler_set_20200130203339_

#include <memory>
#include "ierror_handler_set.hpp"

#include "generic_error_handler.hpp"

namespace fcgisrv {

    class Error_Handler_Set: public IError_Handler_Set {
      private:
        Ptr_t m_handler_401 = std::make_shared<Generic_Error_Handler>(401);
        Ptr_t m_handler_404 = std::make_shared<Generic_Error_Handler>(404);
        Ptr_t m_handler_405 = std::make_shared<Generic_Error_Handler>(405);
        Ptr_t m_handler_500 = std::make_shared<Generic_Error_Handler>(500);

      public:
        std::shared_ptr<IHandler> error_401() override;
        std::shared_ptr<IHandler> error_404() override;
        std::shared_ptr<IHandler> error_405() override;
        std::shared_ptr<IHandler> error_500() override;
    };
} // namespace fcgisrv

#endif