#include <vector>
#include <string>

using namespace std;

class Crawl{
public:
    Crawl(int n_threads, std::vector<std::string>&& urls);
    void start();

private:
    int _n_threads;
    std::vector<std::string> _urls;
};