

#include "default_authenticator.hpp"

using namespace fcgisrv;

bool Default_Authenticator::is_valid(
    std::shared_ptr<IServer_Request_Response>) {
    return true;
}
