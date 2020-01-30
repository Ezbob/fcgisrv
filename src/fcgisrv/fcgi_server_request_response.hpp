
#pragma once

#include <sstream>
#include <iostream>
#include <memory>
#include <cstring>
#include <vector>
#include "fcgio.h"
#include "IFormatted_Response.hpp"
#include "IServer_Request_Response.hpp"

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
        : public IServer_Request_Response
        , public std::enable_shared_from_this<Fcgi_Server_Request_Response> {
        FCGX_Request m_request;
        bool m_is_accepted;
        fcgi_streambuf m_log_stream_buf;
        std::ostream m_log_stream;

      public:
        Fcgi_Server_Request_Response();

        ~Fcgi_Server_Request_Response();

        bool accept() override;

        bool is_accepted() override;

        int respond_with(IFormatted_Response &res) override;

        int respond_with(std::string const &res) override;

        std::ostream &log_out() override;

        char const *get_parameter(std::string const &name) const override;

        const std::vector<const char *> get_parameters() const override;

        std::shared_ptr<Fcgi_Server_Request_Response> get();
    };

};
