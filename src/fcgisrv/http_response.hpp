
#ifndef _HEADER_FILE_response_20200113210402_
#define _HEADER_FILE_response_20200113210402_

#include <string>
#include <sstream>
#include <ostream>

#include "iformatted_response.hpp"
#include "http_error_code.hpp"

namespace fcgisrv {

    class Http_Response: public IFormatted_Response {
      protected:
        std::stringstream m_header;
        std::stringstream m_body;
        Http_Error_Code m_error_code = 200;

      public:
        void put_header(std::string const &raw);

        void put_header(std::string const &name, std::string const &value);

        void status(int code);
        void status(Http_Error_Code const &code);

        int status();

        std::ostream &body();

        std::string render() override;
    };

};

#endif