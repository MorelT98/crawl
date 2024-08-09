#include <vector>
#include <string>

using namespace std;

class CrawlManager{
public:
    CrawlManager(int n_threads, std::vector<std::string>&& urls);
    void start();

private:
    int _n_threads;
    std::vector<std::string> _urls;
};