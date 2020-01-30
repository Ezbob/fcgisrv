

#include "error_handler_set.hpp"

using namespace fcgisrv;

std::shared_ptr<IHandler> Error_Handler_Set::error_401() {
    return m_handler_401;
}

std::shared_ptr<IHandler> Error_Handler_Set::error_404() {
    return m_handler_404;
}

std::shared_ptr<IHandler> Error_Handler_Set::error_405() {
    return m_handler_405;
}

std::shared_ptr<IHandler> Error_Handler_Set::error_500() {
    return m_handler_500;
}
