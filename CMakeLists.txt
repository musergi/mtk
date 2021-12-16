# Global config
cmake_minimum_required(VERSION 3.15)
project(mtk)

# Library
add_library(mtk src/string.c)
target_include_directories(mtk PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Testing
enable_testing()
add_executable(test_string test/string.c)
target_link_libraries(test_string PRIVATE mtk)
add_test(NAME string COMMAND test_string)
