#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <thread>
#include <chrono>
#include <mutex>
#include "CrawlManager.h"

using namespace std;

std::mutex log_mutex;

void log(const std::string& message) {
    std::lock_guard<std::mutex> l(log_mutex);
    cout << message << endl;
}

CrawlManager::CrawlManager(int n_threads, std::vector<std::string>&& urls): _n_threads(n_threads), _urls(urls) {
    cout << "Initialized crawler." << endl;
}

void CrawlManager::start() {
    log("Starting to crawl...");

    std::vector<std::thread> crawlers;

    for(int i = 0; i < _n_threads; i++) {
        auto& url = _urls[i % _urls.size()];
        crawlers.push_back(std::thread([&url]() {
            log("Crawling " + url + "...");
            this_thread::sleep_for(1s);
            log("Crawl of " + url + " complete.");
        }));
    }

    for (auto& crawler: crawlers) {
        crawler.join();
    }

    log("Crawling complete!");
}