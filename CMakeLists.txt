cmake_minimum_required(VERSION 3.15)

set(This SignalSlots)

project(${This} VERSION 0.0.0)

# GoogleTest Framework
# Conditions for Framework
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE)

enable_testing()
add_subdirectory(googletest)

set(Headers
    "include/linked_list.hpp"
    "include/signals.hpp"
)
set(Sources
    "src/signals.cpp"
)

add_library(${This} STATIC ${Sources})
target_include_directories(${This} PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_subdirectory(test)