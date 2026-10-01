# Скачиваем Google Test
include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.14.0
)

# Для Windows — чтобы CRT совпадал с основным проектом
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

add_executable(test_gtest test_dd.cpp)

target_link_libraries(test_gtest PRIVATE util_lib gtest_main)

target_include_directories(test_gtest PRIVATE ${CMAKE_SOURCE_DIR}/src)