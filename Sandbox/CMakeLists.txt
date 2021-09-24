cmake_minimum_required(VERSION 3.14)
project(Sandbox)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)
file (GLOB_RECURSE SOURCES src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} GRender)