

#include "fcgisrv/default_authenticator.hpp"

using namespace fcgisrv;

bool DefaultAuthenticator::is_valid(std::shared_ptr<IServerRequestResponse>) {
    return true;
}
