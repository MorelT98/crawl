cmake_minimum_required(VERSION 3.20)

project(crawl VERSION 1.0)

add_library(crawl_compiler_flags INTERFACE)
target_compile_features(crawl_compiler_flags INTERFACE cxx_std_14)

## MAIN TARGET: Crawl Library
add_library(Crawl Crawl.cpp)
target_link_libraries(Crawl PUBLIC crawl_compiler_flags)

## TEST TARGET: CrawlTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(CrawlTest "${CMAKE_SOURCE_DIR}/test/CrawlTest.cpp")
target_link_libraries(CrawlTest GTest::gtest_main Crawl crawl_compiler_flags)
target_include_directories(CrawlTest PUBLIC "${CMAKE_SOURCE_DIR}")

include(GoogleTest)
gtest_discover_tests(CrawlTest)