cmake_minimum_required(VERSION 3.25)
project(2023-cpl-coding-2 C)

set(CMAKE_C_STANDARD 17)

add_subdirectory(code-style)

add_subdirectory(io)
add_subdirectory(if)
add_subdirectory(for)

add_subdirectory(timing)

add_subdirectory(static)

add_subdirectory(function)

add_subdirectory(string)

add_subdirectory(pointers)

add_subdirectory(misc)