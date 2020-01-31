
#pragma once

#include "http_response.hpp"

namespace fcgisrv {

    struct Json_Response: public Http_Response {
        std::string render() override;
    };

};
