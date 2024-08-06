#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

std::mutex log_mutex;

void log(const std::string& message) {
    std::lock_guard<std::mutex> l(log_mutex);
    cout << message << endl;
}

int main() {
    cout << "C R A W L" << endl;

    std::vector<std::string> input_urls = {
        "http://example.com",
        "http://example.org",
        "http://example.net"
    };

    std::vector<std::thread> crawlers;

    for(auto& url: input_urls) {
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