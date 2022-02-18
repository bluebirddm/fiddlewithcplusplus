cmake_minimum_required(VERSION 3.20)
# change project when modify project name
project(fiddlewithcplusplus)

# includes
set(CMAKE_MODULE_PATH
        "."
        ${CMAKE_MODULE_PATH})

message(STATUS "CMAKE_MODULE_PATH: ${CMAKE_MODULE_PATH}")

include(LetTestSimple.cmake)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 14)

######################################
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(HAVE_CMAKE_GTEST ON)

enable_testing()

######################################

add_executable(
        hello_test
        hello_test.cpp
)
add_executable(
        unique_ptr
        unique_ptr.cpp
)

add_executable(
        vector_insert
        vector_insert.cpp
)

add_executable(
        ceil_test
        ceil_test.cpp
)

######################################

target_link_libraries(
        hello_test
        gtest_main
)

target_link_libraries(
        unique_ptr
        gtest_main
)

target_link_libraries(
        vector_insert
        gtest_main
)

#do not add comma
target_link_libraries(
        ceil_test
        gtest_main
)



######################################

include(GoogleTest)

custom_define_tests(
    DIRECTORY leetcode/
      TEST lc_1268 SOURCES lc_1268.cpp
      TEST lc_2167 SOURCES lc_2167.cpp
      TEST lc_2152 SOURCES lc_2152.cpp
      TEST lc_652 SOURCES lc_652.cpp
      TEST lc_2172 SOURCES lc_2172.cpp
      TEST lc_2002 SOURCES lc_2002.cpp
      TEST lc_759  SOURCES lc_759.cpp
      TEST lc_1157 SOURCES lc_1157.cpp
    DIRECTORY ./
      TEST index_sequence SOURCES index_sequence.cpp
      TEST lower_bound_upper_bound SOURCES lower_bound_upper_bound.cpp
)

#
#gtest_discover_tests(hello_test)
#gtest_discover_tests(unique_ptr)
#gtest_discover_tests(vector_insert)
#gtest_discover_tests(ceil_test)
#gtest_discover_tests(leetcode_lc_1268)
#gtest_discover_tests(index_sequence)

#message(STATUS "dingmao CXXFLAGS : $ENV{CMAKE_CXX_FLAGS_DEBUG}")
message(STATUS "dingmao CMAKE_CXX_FLAGS_DEBUG : ${CMAKE_CXX_FLAGS_DEBUG}")
message(STATUS "dingmao CMAKE_CXX_FLAGS_RELEASE : ${CMAKE_CXX_FLAGS_RELEASE}")
