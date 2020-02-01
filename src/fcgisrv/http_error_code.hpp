#pragma once

#include <string>

namespace fcgisrv {

    class Http_Error_Code {
      private:
        int m_value;

      public:
        Http_Error_Code(int);
        ~Http_Error_Code() = default;

        std::string get_translation() const;
        int to_int() const;
        std::string to_string() const;
    };

};