#include <vector>
#include <queue>

using std::vector;
using std::priority_queue;

// Default: less
class myComparison {
public:
    bool reverse;

public:
    myComparison(const bool &flag = false): reverse(flag) {}
    bool operator () (const std::pair<int, int>& a, const std::pair<int, int>& b) {
        if (reverse) {
            return a.first > b.first;
        }
        return a.first < b.first;
    }
};

typedef std::priority_queue<std::pair<int, int>, vector<std::pair<int, int>>, myComparison> mypq_type;

class Solution {
public:
    // priority queue
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        mypq_type buy;  // less大根堆
        mypq_type sell(myComparison(true)); // greater小根堆
        for (const vector<int>& order : orders) {
            int p = order[0], a = order[1], t = order[2], qty = 0;
            // encounter a type buy order
            if (t == 0) {
                while (a  && !sell.empty() && sell.top().first <= p) {
                    auto [price, amount] = sell.top();
                    sell.pop();
                    qty = std::min(a, amount);
                    amount -= qty;
                    a -= qty;
                    if (amount) sell.push({price, amount});
                }
                if (a)  buy.push({p, a});
            }
            // encounter a type sell order
            else {
                while (a && !buy.empty() && buy.top().first >= p) {
                    auto [price, amount] = buy.top();
                    buy.pop();
                    qty = std::min(a, amount);
                    amount -= qty;
                    a -= qty;
                    if (amount) buy.push({price, amount});
                }
                if (a)  sell.push({p, a});
            }
        }
        int ans = 0;
        while (!sell.empty()) {
            ans = (ans + sell.top().second) % MOD;
            sell.pop();
        }
        while (!buy.empty()) {
            ans = (ans + buy.top().second) % MOD;
            buy.pop();
        }
        return ans;
    }

private:
    static constexpr int MOD = 1e9 + 7;
};