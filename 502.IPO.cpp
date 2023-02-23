#include <vector>
#include <queue>
#include <algorithm>

using std::vector;
using std::priority_queue;


class Solution {
public:
    // priority queue && greedy
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int len = profits.size();
        vector<std::pair<int, int>> vec;
        for (int i = 0; i < len; ++i) {
            vec.emplace_back(capital[i], profits[i]);
        }
        std::sort(vec.begin(), vec.end(), std::less<>());

        priority_queue<int> profit;
        int j = 0;
        for (int i = 0; i < k; ++i) {
            while (j < len && vec[j].first <= w) {
                profit.push(vec[j++].second);
            }
            if (profit.empty()) break;
            // greedy
            w += profit.top();
            profit.pop();
        }
        return w;
    }
};