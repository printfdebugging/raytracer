cmake_minimum_required(VERSION 4.0)
project(raytracer)

set(CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

ADD_EXECUTABLE(
    raytracer
    source/main.cpp
)

TARGET_COMPILE_OPTIONS(raytracer PRIVATE
    -std=c++17
    -g
    -Wall
    -Wextra
    -static
)

TARGET_INCLUDE_DIRECTORIES(raytracer PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

add_custom_target(run
    COMMAND raytracer
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    DEPENDS raytracer
    COMMENT "Running raytracer from root directory"
)
