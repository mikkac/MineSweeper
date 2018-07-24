cmake_minimum_required(VERSION 3.10)
project(MineSweeper_tests)

set(TESTS_FILES
    ${CMAKE_CURRENT_LIST_DIR}/MineSweeperTests.cpp
    )

add_executable(${PROJECT_NAME} ${TESTS_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE ../inc)

target_link_libraries(${PROJECT_NAME} ${MineSweeper_lib})
target_link_libraries(${PROJECT_NAME} gtest gtest_main pthread)
