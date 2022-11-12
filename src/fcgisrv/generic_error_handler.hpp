
#pragma once

#include "ihandler.hpp"
#include "http_error_code.hpp"
#include "http_response.hpp"
#include <string>

namespace fcgisrv {

    class Generic_Error_Handler: public IHandler {
      private:
        Http_Error_Code m_status;
        Http_Response generate_message();

      public:
        Generic_Error_Handler(Http_Error_Code);
        Generic_Error_Handler(int);
        ~Generic_Error_Handler() = default;

        void handle(Fcgi_Request_Response) override;
    };

};
