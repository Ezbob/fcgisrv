CMAKE_MINIMUM_REQUIRED(VERSION 3.1.3)

# Name and description are injected from makefile
PROJECT(fcgisrv)

# Some paths
SET(SOURCES_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/src)
SET(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib)

ADD_SUBDIRECTORY(${LIB_DIR}/libfcgi EXCLUDE_FROM_ALL)

# tests for compiler compliance and sets the C++ standard to C++11
SET(CMAKE_CXX_STANDARD 11)

option(BUILD_EXAMPLES "build examples" ON)

# Sources sets
SET(SOURCES
    ${SOURCES_PREFIX}/fcgisrv/dispatcher.cpp
    ${SOURCES_PREFIX}/fcgisrv/authenticator.cpp
    ${SOURCES_PREFIX}/fcgisrv/fcgi_acceptor.cpp
    ${SOURCES_PREFIX}/fcgisrv/fcgi_server_request_response.cpp
    ${SOURCES_PREFIX}/fcgisrv/fcgi_application.cpp
    ${SOURCES_PREFIX}/fcgisrv/json_response.cpp

    ${SOURCES_PREFIX}/fcgisrv/http_method.cpp
    ${SOURCES_PREFIX}/fcgisrv/http_response.cpp
    ${SOURCES_PREFIX}/fcgisrv/http_error_code.cpp
    ${SOURCES_PREFIX}/fcgisrv/error_handler_set.cpp
    ${SOURCES_PREFIX}/fcgisrv/generic_error_handler.cpp
)

SET(INCLUDES
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

ADD_LIBRARY(fcgisrv SHARED "")

TARGET_SOURCES(fcgisrv PRIVATE ${SOURCES})
TARGET_INCLUDE_DIRECTORIES(fcgisrv PUBLIC ${INCLUDES})
TARGET_LINK_LIBRARIES(fcgisrv PUBLIC fcgi-lib)
TARGET_COMPILE_DEFINITIONS(fcgisrv PRIVATE c_plusplus=1)

# sockets for win and other
if(WIN32)
    TARGET_LINK_LIBRARIES(fcgisrv PRIVATE ws2_32)
else(WIN32)
    FIND_PACKAGE(Threads)
    TARGET_LINK_LIBRARIES(fcgisrv PRIVATE ${CMAKE_THREAD_LIBS_INIT})
endif(WIN32)


ADD_LIBRARY(fcgisrv-static STATIC "")

TARGET_SOURCES(fcgisrv-static PRIVATE ${SOURCES})
TARGET_INCLUDE_DIRECTORIES(fcgisrv-static PUBLIC ${INCLUDES})
TARGET_LINK_LIBRARIES(fcgisrv-static PUBLIC fcgi-lib)
TARGET_COMPILE_DEFINITIONS(fcgisrv-static PRIVATE c_plusplus=1)

set_property(TARGET fcgisrv-static PROPERTY OUTPUT_NAME fcgisrv)

# sockets for win and other
if(WIN32)
    TARGET_LINK_LIBRARIES(fcgisrv-static PRIVATE ws2_32)
else(WIN32)
    FIND_PACKAGE(Threads)
    TARGET_LINK_LIBRARIES(fcgisrv-static PRIVATE ${CMAKE_THREAD_LIBS_INIT})
endif(WIN32)

if(BUILD_EXAMPLES)
    ADD_SUBDIRECTORY(${CMAKE_CURRENT_LIST_DIR}/examples/fcgitest)
endif(BUILD_EXAMPLES)
