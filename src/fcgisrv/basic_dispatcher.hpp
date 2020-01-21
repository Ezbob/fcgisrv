
#ifndef _HEADER_FILE_basic_dispatcher_20200115194648_
#define _HEADER_FILE_basic_dispatcher_20200115194648_

#include <memory>
#include <string>
#include "fcgisrv/http_method.hpp"
#include "basic_handler.hpp"
#include "basic_server_request_response.hpp"

namespace fcgisrv {

    struct BasicDispatcher {
        virtual ~BasicDispatcher() = default;
        virtual void dispatch(std::shared_ptr<BasicServerRequestResponse> req_ptr) = 0;
        virtual void add_endpoint(std::string, HttpMethod, std::shared_ptr<BasicHandler>) = 0;
    };

};

#endif