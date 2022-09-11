#include <vector>
#include <utility>
#include <queue>

using std::vector;
using std::priority_queue;


class Solution {
public:
    // customized sort & priority queue
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<std::pair<int, int>> vec(n);
        for (int i = 0; i < n; ++i) {
            vec[i] = {efficiency[i], speed[i]};
        }
        std::sort(rbegin(vec), rend(vec));
        long sum = 0, ans = 0;
        // simulate a less-than queue
        priority_queue<int, vector<int>, std::greater<>> pq;
        for (auto& [e, s] : vec) {
            pq.emplace(s);
            sum += s;
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            ans = std::max(ans, sum * e);
        }
        return ans % int(1e9 + 7);
    }
};