
#ifndef _HEADER_FILE_response_20200113210402_
#define _HEADER_FILE_response_20200113210402_

#include <string>
#include <sstream>
#include <ostream>
#include "fcgisrv/iformatted_response.hpp"

namespace fcgisrv {

    static const std::string HTTP_LINE_END = "\r\n";

    class HttpResponse: public IFormattedResponse {
      protected:
        std::stringstream m_header;
        std::stringstream m_body;
        int m_error_code = 200;

        std::string translate_code();

      public:
        void put_header(std::string const &raw);

        void put_header(std::string const &name, std::string const &value);

        void status(int code);

        int status();

        std::ostream &body();

        std::string render() override;
    };

    struct JsonResponse: public HttpResponse {
        std::string render() override;
    };

};

#endif