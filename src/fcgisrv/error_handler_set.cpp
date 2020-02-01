

#include "error_handler_set.hpp"

using namespace fcgisrv;

std::shared_ptr<IHandler>
    Error_Handler_Set::get_error(Http_Error_Code const &err) {
    return get_error(err.to_int());
}

std::shared_ptr<IHandler> Error_Handler_Set::get_error(int err) {
    switch (err) {
        case 404:
            return m_handler_404;
        case 401:
            return m_handler_401;
        case 405:
            return m_handler_405;
        case 500:
            return m_handler_500;
        default:
            break;
    }
    return m_handler_500;
}