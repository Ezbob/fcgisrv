

#ifndef _HEADER_FILE_authenticator_20200103164302_
#define _HEADER_FILE_authenticator_20200103164302_

#include "basic_authenticator.hpp"
#include "basic_server_request_response.hpp"
#include <memory>

namespace fcgisrv {

    class DefaultAuthenticator : public BasicAuthenticator {
    public:
        ~DefaultAuthenticator() = default;

        bool is_valid(std::shared_ptr<BasicServerRequestResponse> const &) override;
    };
};

#endif