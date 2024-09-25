cmake_minimum_required(VERSION 3.16)

project(Voxterra LANGUAGES CXX VERSION 0.1.0)

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE RelWithDebInfo)
endif()

set(SOURCE_FILES
    src/main.cpp
    src/window.cpp
    src/player.cpp
    src/block.cpp
    src/resource_manager.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

find_package(Git REQUIRED)

if(Git_FOUND)
  execute_process(
    COMMAND ${GIT_EXECUTABLE} rev-parse --short HEAD
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    OUTPUT_VARIABLE GIT_COMMIT_HASH
    ERROR_QUIET
    OUTPUT_STRIP_TRAILING_WHITESPACE
  )
endif()

if(NOT GIT_COMMIT_HASH)
  set(GIT_COMMIT_HASH "unhashed")
endif()

configure_file(
  src/voxconfig.h.in
  ${CMAKE_CURRENT_BINARY_DIR}/voxconfig.h
)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)

set(OPENGL_VERSION "3.3")

file(
  DOWNLOAD
  https://github.com/cpm-cmake/CPM.cmake/releases/download/v0.38.7/CPM.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake
  EXPECTED_HASH SHA256=83e5eb71b2bbb8b1f2ad38f1950287a057624e385c238f6087f94cdfc44af9c5
)
include(${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake)

CPMAddPackage("gh:raysan5/raylib#5.0")

target_link_libraries(${PROJECT_NAME} raylib)

file(
  GLOB
  PNG_FILES
  "*.png"
)

foreach(PNG_FILE ${PNG_FILES})
  file(
    COPY
    ${PNG_FILE}
    DESTINATION
    ${CMAKE_CURRENT_BINARY_DIR}
  )
endforeach()
