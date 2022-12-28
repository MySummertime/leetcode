#include <vector>
#include <queue>

using std::vector;
using std::priority_queue;


class Solution {
public:
    // priority queue
    int minStoneSum(vector<int>& piles, int k) {
        int ans = 0;
        priority_queue<int> pq;
        for (const int& i : piles) {
            pq.push(i);
            ans += i;
        }
        while (k--) {
            int t = pq.top();
            pq.pop();
            ans -= t - ((t + 1) >> 1);
            t = (t + 1) >> 1;
            pq.push(t);
        }
        return ans;
    }
};