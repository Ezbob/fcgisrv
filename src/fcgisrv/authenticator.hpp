

#ifndef _HEADER_FILE_authenticator_20200103164302_
#define _HEADER_FILE_authenticator_20200103164302_

#include <memory>
#include "iauthenticator.hpp"
#include "iserver_request_response.hpp"

namespace fcgisrv {

    class Authenticator: public IAuthenticator {
      public:
        ~Authenticator() = default;

        bool is_valid(std::shared_ptr<IServer_Request_Response>) override;
    };
};

#endif