#include <gtest/gtest.h>
#include "CrawlManager.h"

TEST(CrawlTest, firstTest) {
    CrawlManager crawlManager(
        5, // n_threads
        {
            "https://example1.com", 
            "https://example2.com", 
            "https://example3.com"
        }
    );
    crawlManager.start();
    ASSERT_EQ(0, 0);
}