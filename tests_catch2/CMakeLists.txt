# Скачиваем Catch2 v2 (однофайловая версия)
include(FetchContent)

FetchContent_Declare(
    catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v2.13.10
)

FetchContent_MakeAvailable(catch2)

add_executable(test_catch2 test_dd.cpp)

target_link_libraries(test_catch2 PRIVATE util_lib Catch2::Catch2)

target_include_directories(test_catch2 PRIVATE ${CMAKE_SOURCE_DIR}/src)