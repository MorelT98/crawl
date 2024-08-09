#include <gtest/gtest.h>
#include "CrawlManager.h"
#include <thread>

TEST(CrawlManagerTest, addUrlSingleThread) {
   std::vector<std::string> urls = {
            "https://example1.com", 
            "https://example2.com", 
            "https://example3.com"
        };
    CrawlManager crawlManager(0 /* n_threads */, urls);
    
    crawlManager.addUrl("random.url");
    ASSERT_EQ(crawlManager.queueSize(), urls.size() + 1);
}

TEST(CrawlManagerTest, addUrlMultipleThreads) {
     std::vector<std::string> urls = {
            "https://example1.com", 
            "https://example2.com", 
            "https://example3.com"
        };
    CrawlManager crawlManager(0 /* n_threads */, urls);
    
    std::vector<std::thread> threads;
    for(int i = 0; i < 4; i++) {
        threads.push_back(std::thread([&crawlManager]() {
            crawlManager.addUrl("https://randomUrl");
        }));
    }

    for(auto& thr: threads) {
        thr.join();
    }

    ASSERT_EQ(crawlManager.queueSize(), urls.size() + threads.size());
}

TEST(CrawlManagerTest, removeUrlSingleThread) {
   std::vector<std::string> urls = {
            "https://example1.com", 
            "https://example2.com", 
            "https://example3.com"
        };
    CrawlManager crawlManager(0 /* n_threads */, urls);
    
    std::string url = crawlManager.removeUrl();
    ASSERT_EQ(url, urls[0]);
    ASSERT_EQ(crawlManager.queueSize(), urls.size() - 1);
}

TEST(CrawlManagerTest, removeUrlMultipleThreads) {
     std::vector<std::string> urls = {
            "https://example1.com", 
            "https://example2.com", 
            "https://example3.com",
            "https://example4.com",
            "https://example5.com"
        };
    CrawlManager crawlManager(0 /* n_threads */, urls);
    
    std::vector<std::thread> threads;
    for(int i = 0; i < 3; i++) {
        threads.push_back(std::thread([&crawlManager]() {
            crawlManager.removeUrl();
        }));
    }

    for(auto& thr: threads) {
        thr.join();
    }

    ASSERT_EQ(crawlManager.queueSize(), urls.size() - threads.size());
}