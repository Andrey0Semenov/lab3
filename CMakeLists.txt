cmake_minimum_required(VERSION 3.14)
project(lab3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Все выходные файлы — в папку bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin)

# --- Библиотека с реализацией ---
add_library(util_lib STATIC src/divided_difference.cpp)
target_include_directories(util_lib PUBLIC src)

# --- Демонстрационная программа ---
add_executable(lab3 src/main.cpp)
target_link_libraries(lab3 PRIVATE util_lib)

# --- Тесты ---
enable_testing()

add_subdirectory(tests_catch2)
add_subdirectory(tests_gtest)