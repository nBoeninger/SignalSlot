cmake_minimum_required(VERSION 3.15)

set(This SignalSlotTests)

set(Sources
    SignalSlotTest.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
    SignalSlots
)

add_test(
    NAME ${This}
    COMMAND ${This}
)