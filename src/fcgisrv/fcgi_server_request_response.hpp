
#pragma once

#include <sstream>
#include <iostream>
#include <memory>
#include <cstring>
#include <vector>
#include "fcgio.h"
#include "iformatted_response.hpp"

namespace fcgisrv {

    /**
     * C++11 shared_ptr wrapper for FCGI requests.
     *
     * For convenience sake, a static factory `create` method is included
     * to create new FcgiReqRes instances that are wrapped in a
     * shared_ptr. A FcgiReqRes instance can also create more shared_ptr to
     * itself by the `get` method.
     *
     * When the reference count reaches zero, the request is finished if it has
     * been accepted.
     */
    class Fcgi_Server_Request_Response
        : public std::enable_shared_from_this<Fcgi_Server_Request_Response> {

      private:
        FCGX_Request m_request;

        bool m_is_accepted;

        fcgi_streambuf m_log_stream_buf;

        std::ostream m_log_stream;

      public:
        Fcgi_Server_Request_Response();

        ~Fcgi_Server_Request_Response();

        /**
         * Was this request accepted this request
         */
        bool is_accepted() const;

        /**
         * Render the formatted response onto the FCGI stdout stream
         */
        int respond_with(IFormatted_Response &res);

        /**
         * output res into the FCGI stdout stream
         */
        int respond_with(std::string const &res);

        /**
         * Get logging stream (the stderr stream) of this request
         */
        std::ostream &log_out();

        /**
         * Get a FCGI parameter from the FCGI environment.
         * If the parameter could not be found in the environment this function returns
         * false and the output parameter "out" is not modified. Otherwise, true is returned
         * and the parameter is copied to "out".
         */
        bool parameter(std::string const &name, std::string &out) const;

        /**
         * Get all FCGI parameters from the FCGI environment.
         */
        const std::vector<std::string> parameters() const;

        /**
         * Get a shared_ptr from this class that extends the life-time
         * of this request-response
         */
        std::shared_ptr<Fcgi_Server_Request_Response> get();
    };

    using Fcgi_Request_Response = std::shared_ptr<Fcgi_Server_Request_Response>;

};
