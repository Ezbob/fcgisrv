
#pragma once

#include "../ihandler.hpp"
#include "../http_error_code.hpp"
#include "../http_response.hpp"
#include <string>

namespace fcgisrv {

    class Error_Handler_Template: public IHandler {
      private:
        Http_Error_Code m_status;
        Http_Response generate_message();

      public:
        Error_Handler_Template(Http_Error_Code);
        ~Error_Handler_Template() = default;

        void handle(std::shared_ptr<IServer_Request_Response>) override;
    };

};
