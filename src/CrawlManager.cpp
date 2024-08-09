#include <iostream>
#include "CrawlManager.h"

using namespace std;


CrawlManager::CrawlManager(int n_threads, std::vector<std::string> urls): _n_threads(n_threads) {
    std::lock_guard l(_queue_mutex);
    for(auto& url: urls) {
        _url_queue.push(url);
    }
}

void CrawlManager::addUrl(std::string url) {
    std::unique_lock l(_queue_mutex);
    _url_queue.push(url);
}

std::string CrawlManager::removeUrl() {
    std::unique_lock l(_queue_mutex);
    std::string url = _url_queue.front();
    _url_queue.pop();
    return url;
}

int CrawlManager::queueSize() {
    std::shared_lock l(_queue_mutex);
    return _url_queue.size();
}

void CrawlManager::start() {
    // initi
}