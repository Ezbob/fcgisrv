
#ifndef _HEADER_FILE_error_handler_set_20200130203339_
#define _HEADER_FILE_error_handler_set_20200130203339_

#include <memory>
#include "ierror_handler_provider.hpp"

#include "generic_error_handler.hpp"

namespace fcgisrv {

    class Error_Handler_Set: public IError_Handler_Provider {
      private:
        std::shared_ptr<IHandler> m_handler_401 =
            std::make_shared<Generic_Error_Handler>(401);
        std::shared_ptr<IHandler> m_handler_404 =
            std::make_shared<Generic_Error_Handler>(404);
        std::shared_ptr<IHandler> m_handler_405 =
            std::make_shared<Generic_Error_Handler>(405);
        std::shared_ptr<IHandler> m_handler_500 =
            std::make_shared<Generic_Error_Handler>(500);

      public:
        std::shared_ptr<IHandler> get_error(Http_Error_Code const &) override;
        std::shared_ptr<IHandler> get_error(int) override;
    };
} // namespace fcgisrv

#endif