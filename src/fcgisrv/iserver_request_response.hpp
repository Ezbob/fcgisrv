
#pragma once

#include <vector>

#include "iformatted_response.hpp"

namespace fcgisrv {

    /**
     * Server request response class.
     * This class represents the link to the HTTP server.
     * As such, fcgi parameters and response data is read by, and submitted to,
     * methods of this class.
     */
    struct IServer_Request_Response {
        virtual ~IServer_Request_Response() = default;

        /**
         * Accepting incoming client requests from the server
         */
        virtual bool accept() = 0;

        /**
         *  Returns whether the request has been accepted.
         *  Acceptance is usually done by the acceptor.
         */
        virtual bool is_accepted() = 0;

        /**
         * Sends a response to the server.
         */
        virtual int respond_with(IFormatted_Response &) = 0;

        /**
         * Returns a stream that can be used to send log messages
         * to the HTTP server.
         */
        virtual std::ostream &log_out() = 0;

        /**
         * Send a response to the server using a raw string instead of a
         * formatted IFormattedResponse response
         */
        virtual int respond_with(std::string const &) = 0;

        /**
         * Get a fcgi parameter indexed by a name
         */
        virtual char const *get_parameter(std::string const &) const = 0;

        /**
         * Get a vector of all the fcgi parameters associated with this
         * instance.
         */
        virtual const std::vector<const char *> get_parameters() const = 0;
    };

};
