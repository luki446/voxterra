cmake_minimum_required(VERSION 3.16)

project(Voxterra LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_FILES
    src/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

include(${CMAKE_SOURCE_DIR}/cmake/CPM.cmake)

CPMAddPackage("gh:raysan5/raylib#5.0")

target_link_libraries(${PROJECT_NAME} raylib)
