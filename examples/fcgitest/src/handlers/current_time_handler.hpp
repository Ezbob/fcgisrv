
#pragma once

#include "fcgisrv/fcgisrv.hpp"
#include <ctime>

namespace fcgitest {

    class Current_Time_Handler: public fcgisrv::IHandler {
      public:
        void handle(fcgisrv::Fcgi_Request_Response) override;
    };

}; // namespace fcgitest
