cmake_minimum_required(VERSION 3.16)

project(protobuf-mutator-example)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
include(external/protobuf)
include(external/libprotobuf-mutator)

find_package(cifuzz NO_SYSTEM_ENVIRONMENT_PATH)
enable_fuzz_testing()

add_subdirectory(src)
add_subdirectory(test)
