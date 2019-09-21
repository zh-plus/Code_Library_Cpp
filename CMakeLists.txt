cmake_minimum_required(VERSION 3.13)
project(Code_Library)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 99)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif ()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(src)

add_executable(cpp_study study/ATourOfCpp/ATC_4_2.cpp)
add_executable(c_study study/ModernC/MC_1.c)

add_executable(easy LeetCode/easy/70_ClimbingStairs.cpp)
add_executable(medium LeetCode/medium/19_RemoveNthNodeFromEndOfList.cpp)
add_executable(hard LeetCode/hard/23_MergeKSortedLists.cpp)

add_executable(STL study/CppSTL/regex.cpp)
add_executable(template template/Dijkstra.cpp)

add_executable(E Codeforces/EducationalRound73_div2/E.cpp)
add_executable(solving Codeforces/EducationalRound73_div2/solving.cpp)

add_executable(interviews Interviews/ShunFeng/NumOfStudyMachine.cpp)