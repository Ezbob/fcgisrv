

#ifndef _HEADER_FILE_authenticator_20200103164302_
#define _HEADER_FILE_authenticator_20200103164302_

#include "iauthenticator.hpp"
#include "iserver_request_response.hpp"
#include <memory>

namespace fcgisrv {

    class DefaultAuthenticator : public IAuthenticator {
    public:
        ~DefaultAuthenticator() = default;

        bool is_valid(std::shared_ptr<IServerRequestResponse>) override;
    };
};

#endif