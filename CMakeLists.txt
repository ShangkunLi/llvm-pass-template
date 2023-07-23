cmake_minimum_required(VERSION 3.17)
project(Hello)

# set the version of C++
set(CMAKE_CXX_STANDARD 17)

find_package(LLVM REQUIRED CONFIG)
add_definitions(${LLVM_DEFINITIONS})
include_directories(${LLVM_INCLUDE_DIRS})
link_directories(${LLVM_LIBRARY_DIRS})

add_subdirectory(Hello)  # Use your library's directory name here, which is defined in the directory llvm-pass-Hello/Hello
