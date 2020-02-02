
#ifndef _HEADER_FILE_response_20200113210402_
#define _HEADER_FILE_response_20200113210402_

#include <string>
#include <sstream>
#include <ostream>

#include "iformatted_response.hpp"
#include "http_error_code.hpp"

namespace fcgisrv {

    /**
     * HTTP formatted response.
     * This class is responsible for creating a response string
     * that is formatted according to the HTTP protocol.
     */
    class Http_Response: public IFormatted_Response {
      protected:
        std::stringstream m_header;
        std::stringstream m_body;
        Http_Error_Code m_error_code = 200;

      public:
        /**
         * Add a HTTP header field to the formatted response.
         * This overloaded method adds the header verbatim string
         * to the response.
         */
        void put_header(std::string const &raw);

        /**
         * Add a HTTP header field to the formatted response.
         * This will add the header formatted according to the
         * "<name>:<value>" header entry syntax.
         */
        void put_header(std::string const &name, std::string const &value);

        /**
         * Set the status code of the formatted response.
         */
        void status(int code);

        /**
         * Set the status code of the formatted response.
         */
        void status(Http_Error_Code const &code);

        /**
         * Get the status code of the formatted response.
         */
        Http_Error_Code status() const;

        /**
         * Returns a ostream which can be used to insert formatted
         * strings into the body of the response.
         */
        std::ostream &body();

        /**
         * Overloaded from interface base.
         * First adds all headers and then adds the body to the
         * raw response string and returns it.
         */
        std::string render() override;
    };

};

#endif