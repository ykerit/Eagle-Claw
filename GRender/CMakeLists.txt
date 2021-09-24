cmake_minimum_required(VERSION 3.14)

project(GRender)
set(CMAKE_CXX_STANDARD 17)

include_directories(third_party/spdlog/include)
include_directories(third_party/glad/include)
include_directories(third_party/glfw/include)
include_directories(third_party/glm)
include_directories(third_party/imgui)
include_directories(third_party/ImGuizmo)
include_directories(third_party/stb_image)

add_subdirectory(third_party/glm)
add_subdirectory(third_party/glfw)
add_subdirectory(third_party/spdlog)

set(IMGUI_SRC
    third_party/imgui/imgui.h
    third_party/imgui/imgui.cpp
    third_party/imgui/imgui_widgets.cpp
    third_party/imgui/imgui_demo.cpp
    third_party/imgui/imgui_draw.cpp)

set(GLAD_SRC third_party/glad/src/glad.c)

# GRender source files
file(GLOB_RECURSE SOURCES src/core/impl/*.cpp src/platform/GLFWindow/impl/*.cpp src/platform/GL/impl/*.cpp src/renderer/impl/*.cpp)
message(STATUS ${SOURCES})
set(INTERFACE ${PROJECT_SOURCE_DIR}/src/core/include ${PROJECT_SOURCE_DIR}/src/renderer/include ${PROJECT_SOURCE_DIR}/src/platform/GL/include ${PROJECT_SOURCE_DIR}/src/platform/GLFWindow/include)
message(STATUS ${INTERFACE})

add_library(${PROJECT_NAME} STATIC ${SOURCES} ${IMGUI_SRC} ${STBIMG_SRC} ${GLAD_SRC})
foreach (INCPATH IN LISTS INTERFACE)
    target_include_directories(${PROJECT_NAME}
        PUBLIC $<BUILD_INTERFACE:${INCPATH}>
    )
endforeach()
target_link_libraries(${PROJECT_NAME} glfw spdlog glm)