
#pragma once

#include <ostream>
#include <string>

namespace fcgisrv {
    struct IFormatted_Response {
        virtual ~IFormatted_Response() = default;
        virtual std::string render() = 0;
    };
}; // namespace fcgisrv
