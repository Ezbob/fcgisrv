
#pragma once

#include <ostream>
#include <string>

namespace fcgisrv {
    struct IFormattedResponse {
        virtual ~IFormattedResponse() = default;
        virtual std::string render() = 0;
    };
}; // namespace fcgisrv
