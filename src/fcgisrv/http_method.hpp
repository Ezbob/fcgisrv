
#ifndef _HEADER_FILE_method_20200113205822_
#define _HEADER_FILE_method_20200113205822_

#include <string>
#include <functional>

namespace fcgisrv {
    class Http_Method {

      public:
        enum { Get, Post, Put, Patch, Delete, Options, Not_a_method };

        Http_Method(int b = Not_a_method);

        bool operator==(Http_Method const &);
        bool operator!=(Http_Method const &);

        int to_int() const;
        std::string to_string() const;
        static Http_Method from_string(std::string const &);

      private:
        int m_value;
    };

};

template<>
struct std::hash<fcgisrv::Http_Method> {
    inline size_t operator()(fcgisrv::Http_Method const &x) const {
        static std::hash<int> hasher;
        return hasher(x.to_int());
    }
};

template<>
struct std::equal_to<fcgisrv::Http_Method> {
    inline bool operator()(fcgisrv::Http_Method const &l,
                           fcgisrv::Http_Method const &r) const {
        return l.to_int() == r.to_int();
    }
};

#endif