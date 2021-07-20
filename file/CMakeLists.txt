cmake_minimum_required(VERSION 3.12)
project(main)

set(CMAKE_CXX_STANDARD 11)

##########################################################################

set(CPPRESTSDK_INCLUDE_DIR /usr/local/Cellar/cpprestsdk/2.10.18/include)
set(CPPRESTSDK_SOURCE_DIR /usr/local/Cellar/cpprestsdk/2.10.18/lib)

set(OPENSSL_INCLUDE_DIR /usr/local/Cellar/openssl\@1.1/1.1.1k/include)
set(OPENSSL_SOURCE_DIR /usr/local/Cellar/openssl\@1.1/1.1.1k/lib)

set(BOOST_INCLUDE_DIR /usr/local/Cellar/boost/1.76.0/include)
set(BOOST_SOURCE_DIR /usr/local/Cellar/boost/1.76.0/lib)

##########################################################################

set(SOURCES
        BingSearch.cpp
)

##########################################################################

include_directories(${OPENSSL_INCLUDE_DIR})
include_directories(${CPPRESTSDK_INCLUDE_DIR})
include_directories(${BOOST_INCLUDE_DIR})

##########################################################################

add_executable(main ${SOURCES})

message(STATUS "foo include dir: ${CPPRESTSDK_SOURCE_DIR}")

target_link_libraries(main
${CPPRESTSDK_SOURCE_DIR}/libcpprest.2.10.dylib
${CPPRESTSDK_SOURCE_DIR}/libcpprest.dylib
${OPENSSL_SOURCE_DIR}/libssl.dylib
${OPENSSL_SOURCE_DIR}/libcrypto.dylib
${BOOST_SOURCE_DIR}/libboost_system.dylib
)
