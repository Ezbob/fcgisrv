
#ifndef _HEADER_FILE_handler_response_20200110190205_
#define _HEADER_FILE_handler_response_20200110190205_

#include <ostream>
#include <string>

namespace fcgisrv
{
struct IFormattedResponse
{
    virtual ~IFormattedResponse() = default;
    virtual std::string render() = 0;
};
}; // namespace fcgisrv

#endif