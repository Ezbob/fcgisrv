
#ifndef _HEADER_FILE_basic_request_response_20200115205041_
#define _HEADER_FILE_basic_request_response_20200115205041_

#include <vector>
#include "iformatted_response.hpp"

namespace fcgisrv {

    struct IServerRequestResponse {
        virtual ~IServerRequestResponse() = default;

        /**
         * Accepting incoming client requests from the server
         */
        virtual bool accept() = 0;

        /**
         *  Is the request-response already accepted?
         */
        virtual bool is_accepted() = 0;

        /**
         * Send a response to the server
         */
        virtual int respond_with(IFormattedResponse &) = 0;

        /**
         * Send a response to the server using a raw string instead of a
         * formatted IFormattedResponse response
         */
        virtual int respond_with(std::string const&) = 0;
        virtual char const *get_parameter(std::string const &) const = 0;
        virtual const std::vector<const char *> get_parameters() const = 0;
    };

};

#endif
