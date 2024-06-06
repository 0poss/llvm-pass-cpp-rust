find_package(LLVM 17 REQUIRED CONFIG)
add_definitions(${LLVM_DEFINITIONS})
include_directories(SYSTEM ${LLVM_INCLUDE_DIRS})

set(SRCS
    Pass.cpp)

add_library(${PROJECT_NAME}Pass
    SHARED
    ${SRCS})

set(CMAKE_CXX_FLAGS "-I ${LLVM_INCLUDE_DIRS}")
