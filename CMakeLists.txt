cmake_minimum_required(VERSION 3.20)

set(PROJECT_NAME project)

project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")
if(CMAKE_EXPORT_COMPILE_COMMANDS)
  set(CMAKE_CXX_STANDARD_INCLUDE_DIRECTORIES
    ${CMAKE_CXX_IMPLICIT_INCLUDE_DIRECTORIES})
endif()

add_subdirectory(${PROJECT_NAME}-rs)
include_directories(${RUST_LIB_BINDINGS_DIR})

add_definitions(-DPROJECT_NAME="${PROJECT_NAME}")
include_directories(include/)
add_subdirectory(src)

target_link_libraries(${PROJECT_NAME}Pass
    PUBLIC
    ${PROJECT_NAME}_rs)
