cmake_minimum_required(VERSION 3.13)
project(Code_Library CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 99)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif ()

set(CMAKE_CXX_FLAGS_RELEASE "-Ofast")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

find_package(Boost)
if (Boost_FOUND)
    message("Boost found: " ${Boost_VERSION})
    include_directories(${Boost_INCLUDE_DIRS})
endif ()

add_executable(cpp_study study/ATourOfCpp/ATC_7.cpp)
add_executable(my_study study/sundries/smart_pointers.cpp)
add_executable(c_study study/PPPUC/vector_refinement.cpp)

add_executable(easy LeetCode/easy/35_SearchInsertPosition.cpp)
add_executable(medium LeetCode/medium/36_ValidSudoku.cpp)
add_executable(hard LeetCode/hard/76_MinimumWindowSubstring.cpp)

add_executable(STL study/CppSTL/timer.cpp)
add_executable(template template/tools.cpp)
add_executable(random_test test/cin_test.cpp)

add_executable(A Codeforces/Round627_div3/A.cpp)
add_executable(solving Codeforces/Round627_div3/solving.cpp)

add_executable(interviews Interviews/ShunFeng/NumOfStudyMachine.cpp)

target_link_libraries(template ${Boost_LIBRARIES})