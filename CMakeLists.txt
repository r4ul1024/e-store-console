cmake_minimum_required(VERSION 3.10)
project(e-store-console)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES "src/*.cpp")

add_executable(e-store-console ${SOURCES})

target_include_directories(e-store-console PRIVATE include)
