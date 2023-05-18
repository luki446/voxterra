cmake_minimum_required(VERSION 3.16)

project(Voxterra LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_FILES
    src/main.cpp
    src/window.cpp
    src/shader.cpp
    src/vao.cpp
    src/vbo.cpp
    src/texture.cpp

    src/stb/stb_image.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

include(cmake/CPM.cmake)

CPMAddPackage(
    NAME GLFW
    GITHUB_REPOSITORY glfw/glfw
    GIT_TAG 3.3.8
    OPTIONS
    "GLFW_BUILD_TESTS OFF"
    "GLFW_BUILD_EXAMPLES OFF"
    "GLFW_BULID_DOCS OFF"
)

CPMAddPackage("gh:Dav1dde/glad@0.1.34")
CPMAddPackage("gh:g-truc/glm#0.9.9.8")
CPMAddPackage("gh:gabime/spdlog@1.11.0")

target_link_libraries(${PROJECT_NAME} glfw glad spdlog)