

#ifndef _HEADER_FILE_authenticator_20200103164302_
#define _HEADER_FILE_authenticator_20200103164302_

#include <memory>
#include "IAuthenticator.hpp"
#include "IServer_Request_Response.hpp"

namespace fcgisrv {

    class Default_Authenticator: public IAuthenticator {
      public:
        ~Default_Authenticator() = default;

        bool is_valid(std::shared_ptr<IServer_Request_Response>) override;
    };
};

#endif