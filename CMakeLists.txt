cmake_minimum_required(VERSION 2.6)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

include_directories(include)
add_library(cell SHARED src/cell.cpp)
add_library(game SHARED src/game.cpp)
add_executable(app src/main.cpp)
add_executable(runTests src/tests.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread cell)

