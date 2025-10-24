cmake_minimum_required(VERSION 3.10)
project(FigureProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.0
  TLS_VERIFY false
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(include)

add_library(figures_lib
    src/Array.cpp
    src/Figure.cpp
    src/Hexagon.cpp
    src/Octagon.cpp
    src/Triangle.cpp
)

add_executable(figure_app src/main.cpp)
target_link_libraries(figure_app PRIVATE figures_lib)

add_executable(tests test/tests.cpp)
target_link_libraries(tests PRIVATE figures_lib GTest::gtest_main)

enable_testing()
add_test(NAME FiguresUnitTests COMMAND tests)
