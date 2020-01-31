
#pragma once

#include "http_response.hpp"

namespace fcgisrv {

    struct JsonResponse: public Http_Response {
        std::string render() override;
    };

};
