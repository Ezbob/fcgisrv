
#include "echo_handler.hpp"

#include <stdlib.h>
#ifdef _WIN32
#include <process.h>
#else
#include <unistd.h>
extern char **environ;
#endif

using namespace fcgitest;

void Echo_Handler::penv(const char *const *envp, std::ostream &stream) {
    stream << "<pre>" << fcgisrv::HTTP_LINE_END;
    for (; *envp; ++envp) {
        stream << *envp << fcgisrv::HTTP_LINE_END;
    }
    stream << "</pre>";
}

void Echo_Handler::penv(const std::vector<std::string> &envp,
                        std::ostream &stream) {
    stream << "<pre>" << fcgisrv::HTTP_LINE_END;
    for (auto c : envp) {
        stream << c << fcgisrv::HTTP_LINE_END;
    }
    stream << "</pre>";
}

void Echo_Handler::handle(fcgisrv::Fcgi_Request_Response rr) {

    fcgisrv::Http_Response resp;
    std::ostream &out = resp.body();

    resp.put_header("Content-type", "text/html");

    out << "<html>";
    out << "<head>"
           "<title>echo-cpp</title>"
           "<meta charset=\"UTF-8\">"
           "</head>";

    out << "<body>"
           "<h1>echo-cpp</h1>"
           "<h4>PID: "
        << g_pid
        << "</h4>"
           "<h4>Request Number: "
        << ++g_count
        << "</h4>"
           "<h4>Process/Initial Environment</h4>";

    penv(environ, out);

    out << "<h4>Fcgi Environment</h4>";

    auto parameters = rr->parameters();
    penv(parameters, out);

    out << "</body>"
           "</html>";

    rr->log_out() << "Not an error\n";

    rr->respond_with(resp);
}