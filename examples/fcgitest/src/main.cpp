
#include "asio.hpp"
#include "fcgisrv/fcgisrv.hpp"
#include "fcgisrv_shims/asio_scheduler.hpp"

#include "handlers/echo_handler.hpp"
#include "handlers/current_time_handler.hpp"

int main(void) {
    asio::io_context io;
    asio::io_context::work work_io(io);

    fcgisrv::Fcgi_Application app(
        std::make_shared<fcgisrv::Asio_Scheduler>(io));

    app.add_get("/", std::make_shared<fcgitest::Echo_Handler>());
    app.add_get("/time", std::make_shared<fcgitest::Current_Time_Handler>());

    app.start_nonblock();

    io.run();

    return 0;
}
