

#include "authenticator.hpp"

using namespace fcgisrv;

bool Authenticator::is_valid(std::shared_ptr<IServer_Request_Response>) {
    return true;
}
