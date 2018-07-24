cmake_minimum_required(VERSION 3.10)
project(MineSweeper)

set(CMAKE_CXX_STANDARD 14)
add_compile_options("-Wall" "-Wextra" "-pedantic" "-O2")

set (SOURCE_FILES
    ${CMAKE_CURRENT_LIST_DIR}/src/MineSweeper.cpp
   )

set (HEADER_FILES
    ${CMAKE_CURRENT_LIST_DIR}/inc/MineSweeper.hpp
    )

# add libraries here
set(MineSweeper_lib "MineSweeper_lib")
add_library(${MineSweeper_lib} ${SOURCE_FILES} ${HEADER_FILES})
add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} ${MineSweeper_lib})

include_directories(inc)

add_subdirectory(tests)
