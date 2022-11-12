
#pragma once

#include "fcgisrv/fcgisrv.hpp"

namespace fcgitest {

    static long g_pid = _getpid();
    static int g_count = 0;

    class Echo_Handler: public fcgisrv::IHandler {
      private:
        void penv(const char *const *, std::ostream &);
        void penv(const std::vector<std::string> &, std::ostream &);

      public:
        void handle(fcgisrv::Fcgi_Request_Response);
    };

} // namespace fcgisrv
