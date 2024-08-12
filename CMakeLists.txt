cmake_minimum_required(VERSION 3.28)
project(2048game)

set(CMAKE_CXX_STANDARD 17)
include_directories(./easyx/include)
link_directories(./easyx/lib64)
link_libraries(libeasyx.a)

add_executable(2048game main.cpp
        config/base.h
        config/impl/baseimpl.cpp)

