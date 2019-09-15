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

add_executable(easy LeetCode/easy/21_MergeTwoSortedLists.cpp)
add_executable(medium LeetCode/medium/16_3SumClosest.cpp)
add_executable(hard LeetCode/hard/1178_NumberOfValidWordsForEachPuzzle.cpp)

add_executable(STL study/CppSTL/priority_queue.cpp)
add_executable(template template/Dijkstra.cpp)

add_executable(AB Codeforces/Round584_div12/A.cpp)
add_executable(solving Codeforces/Round584_div12/solving.cpp)

add_executable(interviews Interviews/ShunFeng/NumOfStudyMachine.cpp)