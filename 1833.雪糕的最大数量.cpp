#include <vector>
#include <queue>
#include <algorithm>

using std::vector;
using std::priority_queue;


class Solution1 {
public:
    // greedy && sort
    int maxIceCream(vector<int>& costs, int coins) {
        std::sort(costs.begin(), costs.end(), std::less<>());
        int ans = 0;
        for (const int& i : costs) {
            if (coins >= i) {
                ++ans;
                coins -= i;
            }
        }
        return ans;
    }
};


class Solution1 {
public:
    // priority queue
    int maxIceCream(vector<int>& costs, int coins) {
        priority_queue<int, vector<int>, std::less<>> pq;
        int ans = 0;
        int cur = 0;
        for (const int& i : costs) {
            if (cur + i  <= coins) {
                pq.push(i);
                cur += i;
                ++ans;
            }
            else if (cur && i < pq.top()) {
                cur -= pq.top();
                cur += i;
                pq.pop();
                pq.push(i);
            }
        }
        return ans;
    }
};