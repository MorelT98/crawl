cmake_minimum_required(VERSION 3.20)

add_library(crawlbase CrawlManager.cpp)
target_link_libraries(crawlbase PUBLIC crawl_compiler_flags)

target_include_directories(crawlbase PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")