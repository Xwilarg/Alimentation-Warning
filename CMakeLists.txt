cmake_minimum_required(VERSION 3.1)
project(AlimentationWarning)


if(MSVC)
    SET(CMAKE_CXX_FLAGS "/W4 /EHsc")
else()
    message(FATAL_ERROR "This program is for Windows only (you need to use MSVC to compile this)")
endif()
file(GLOB_RECURSE SRCS "src/*.cpp")
include_directories(inc)
add_executable(${PROJECT_NAME} ${SRCS})