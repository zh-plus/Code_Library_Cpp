cmake_minimum_required(VERSION 3.13)
project(Code_Library)

set(CMAKE_CXX_STANDARD 17)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

include_directories(src)

add_executable(test study/hello_world.cpp)
add_executable(chapter1 study/ATC_1.cpp)
add_executable(chapter2 study/ATC_2.cpp)