
#ifndef _HEADER_FILE_basic_authenticator_20200115204611_
#define _HEADER_FILE_basic_authenticator_20200115204611_

#include <memory>
#include "iserver_request_response.hpp"

namespace fcgisrv
{

struct IAuthenticator
{
    virtual ~IAuthenticator() = default;
    virtual bool is_valid(std::shared_ptr<IServerRequestResponse> const &) = 0;
};

}; // namespace fcgisrv

#endif