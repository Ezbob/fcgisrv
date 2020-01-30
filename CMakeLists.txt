CMAKE_MINIMUM_REQUIRED(VERSION 3.1.3)

# Name and description are injected from makefile
PROJECT(${PROJECT_NAME})

# Some paths
SET(SOURCES_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/src)
SET(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib)

ADD_SUBDIRECTORY(${LIB_DIR}/libfcgi)

# tests for compiler compliance and sets the C++ standard to C++11
SET(CMAKE_CXX_STANDARD 11)

# A set of compilation flags that is always on when compiling C++
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Dc_plusplus")

# Compilation flags that depends on build type
# A symbol _DEBUG is exposed to enable conditional compilation through preprocessor directives
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_DEBUG -g")
SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

# Sources sets
SET(SOURCES
    ${SOURCES_PREFIX}/fcgisrv/dispatcher.cpp
    ${SOURCES_PREFIX}/fcgisrv/authenticator.cpp
    ${SOURCES_PREFIX}/fcgisrv/fcgi_acceptor.cpp
    ${SOURCES_PREFIX}/fcgisrv/fcgi_server_request_response.cpp
    ${SOURCES_PREFIX}/fcgisrv/fcgi_application.cpp

    ${SOURCES_PREFIX}/fcgisrv/http_method.cpp
    ${SOURCES_PREFIX}/fcgisrv/http_response.cpp
    ${SOURCES_PREFIX}/fcgisrv/error_handler_set.cpp
    ${SOURCES_PREFIX}/fcgisrv/default_handlers/internal_server_error_handler.cpp
    ${SOURCES_PREFIX}/fcgisrv/default_handlers/method_not_allowed_handler.cpp
    ${SOURCES_PREFIX}/fcgisrv/default_handlers/not_found_handler.cpp
    ${SOURCES_PREFIX}/fcgisrv/default_handlers/unauthorized_handler.cpp
)

SET(INCLUDES
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# lib without the main file
ADD_LIBRARY(fcgisrv SHARED "")
TARGET_SOURCES(fcgisrv PRIVATE ${SOURCES})
TARGET_INCLUDE_DIRECTORIES(fcgisrv PUBLIC ${INCLUDES})
TARGET_LINK_LIBRARIES(fcgisrv PUBLIC fcgi-lib)
TARGET_COMPILE_OPTIONS(fcgisrv PRIVATE "-fPIC")

# sockets for win and other
if(WIN32)
    TARGET_LINK_LIBRARIES(fcgisrv PRIVATE ws2_32)
else(WIN32)
    FIND_PACKAGE(Threads)
    TARGET_LINK_LIBRARIES(fcgisrv PRIVATE ${CMAKE_THREAD_LIBS_INIT})
endif(WIN32)
