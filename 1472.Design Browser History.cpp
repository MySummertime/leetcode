#include <string>
#include <vector>

using std::string;
using std::vector;


/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        history.emplace_back(homepage);
        idx = 0;
    }

    void visit(string url) {
        history.resize(idx + 1);
        history.push_back(url);
        ++idx;
    }

    string back(int steps) {
        int prev = std::max(0, idx - steps);
        idx = prev;
        return history[idx];
    }

    string forward(int steps) {
        int next = std::min((int)history.size() - 1, idx + steps);
        idx = next;
        return history[idx];
    }

private:
    vector<string> history;
    int idx;
};
