#include <gtest/gtest.h>
#include "Crawl.h"

TEST(main, teststub) {
    Crawl crawl(
        5, // n_threads
        {
            "https://example1.com", 
            "https://example2.com", 
            "https://example3.com"
        }
    );
    crawl.start();
    ASSERT_EQ(0, 0);
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}