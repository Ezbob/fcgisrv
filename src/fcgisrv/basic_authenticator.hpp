
#ifndef _HEADER_FILE_basic_authenticator_20200115204611_
#define _HEADER_FILE_basic_authenticator_20200115204611_

#include <memory>
#include "basic_server_request_response.hpp"

namespace fcgisrv {

    struct BasicAuthenticator {
        virtual ~BasicAuthenticator() = default;
        virtual bool is_valid(std::shared_ptr<BasicServerRequestResponse> const&) = 0;
    };

};

#endif