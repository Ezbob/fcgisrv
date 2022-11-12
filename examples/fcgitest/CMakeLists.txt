CMAKE_MINIMUM_REQUIRED(VERSION 3.15.0)

# Name and description are injected from makefile
PROJECT(fcgitest
    VERSION 0.1
    DESCRIPTION "fcgitest is a test example of using fcgisrv with ASIO"
    LANGUAGES CXX C
)

# Some paths
SET(SOURCES_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/src)
SET(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib)

SET(CMAKE_CXX_STANDARD 11)

# Sources sets
SET(SOURCES
    ${SOURCES_PREFIX}/fcgisrv_shims/asio_scheduler.cpp
    ${SOURCES_PREFIX}/handlers/current_time_handler.cpp
    ${SOURCES_PREFIX}/handlers/echo_handler.cpp
    ${SOURCES_PREFIX}/main.cpp
)

SET(INCLUDES
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${LIB_DIR}/asio/asio/include
)

ADD_EXECUTABLE(fcgitest "")

TARGET_SOURCES(fcgitest PRIVATE ${SOURCES})
TARGET_INCLUDE_DIRECTORIES(fcgitest PRIVATE ${INCLUDES})
TARGET_LINK_LIBRARIES(fcgitest PRIVATE fcgisrv)
TARGET_COMPILE_DEFINITIONS(fcgitest PRIVATE ASIO_STANDALONE=1)

# sockets for win and other
if(WIN32)
    TARGET_LINK_LIBRARIES(fcgitest PRIVATE ws2_32)
else(WIN32)
    FIND_PACKAGE(Threads)
    TARGET_LINK_LIBRARIES(fcgitest PRIVATE ${CMAKE_THREAD_LIBS_INIT})
endif(WIN32)
