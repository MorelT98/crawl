#include <vector>
#include <string>
#include <queue>
#include <shared_mutex>

using namespace std;

class CrawlManager{
public:
    CrawlManager(int n_threads, std::vector<std::string> urls);
    void start();

    void addUrl(std::string url);
    std::string removeUrl();
    int queueSize();

private:
    int _n_threads;
    std::shared_mutex _queue_mutex;
    std::queue<std::string> _url_queue;
};