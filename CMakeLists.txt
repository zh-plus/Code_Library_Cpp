cmake_minimum_required(VERSION 3.13)
project(Code_Library)

set(CMAKE_CXX_STANDARD 17)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(src)

add_executable(study study/ATC_4.cpp)

add_executable(medium LeetCode/medium/34_FindFirstAndLastPositionOfElementInSortedArray.cpp)
add_executable(easy LeetCode/easy/MaximumSubarray.cpp)

add_executable(C Codeforces/Round582_div3/C.cpp)
add_executable(solving Codeforces/Round582_div3/solving.cpp)

add_executable(interviews Interviews/ShunFeng/NumOfStudyMachine.cpp)