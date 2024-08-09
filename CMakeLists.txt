cmake_minimum_required(VERSION 3.20)
project(crawl LANGUAGES CXX VERSION 1.0)

add_library(crawl_compiler_flags INTERFACE)
target_compile_features(crawl_compiler_flags INTERFACE cxx_std_17)

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)