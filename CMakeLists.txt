cmake_minimum_required(VERSION 3.25.1)
project(llist C)

set(CMAKE_C_STANDARD 11)

add_compile_options(-Wextra -Wall -fsanitize=address,undefined)
add_link_options(-fsanitize=address,undefined)

add_library(llist SHARED src/llist.c
        test/llist_test.c)

enable_testing()

add_executable(LListTest test/llist_test.c)

target_link_libraries(LListTest llist)

add_test(NAME LListTest COMMAND LListTest)

# https://cmake.org/cmake/help/book/mastering-cmake/chapter/Testing%20With%20CMake%20and%20CTest.html
