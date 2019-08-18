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

add_executable(chapter1 study/ATC_1.cpp)
add_executable(chapter2 study/ATC_2.cpp)
add_executable(A Codeforces/Round579_div2/A.cpp)
add_executable(B Codeforces/Round579_div2/B.cpp)
add_executable(C Codeforces/Round579_div2/C.cpp)
add_executable(D Codeforces/Round579_div2/D.cpp)