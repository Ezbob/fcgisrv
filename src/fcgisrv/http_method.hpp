
#ifndef _HEADER_FILE_method_20200113205822_
#define _HEADER_FILE_method_20200113205822_

#include <string>

namespace fcgisrv {
    class Http_Method {

      public:
        enum { Get, Post, Put, Patch, Delete, Options, Not_a_method };

        Http_Method(int b = Not_a_method);

        bool operator==(Http_Method const &);
        bool operator!=(Http_Method const &);

        std::string to_string() const;
        static Http_Method from_string(std::string const &);

      private:
        int m_value;
    };

};

#endif