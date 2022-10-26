#include <vector>
#include <deque>

using std::vector;
using std::deque;


class Solution {
public:
    // presum
    int shortestSubarray(vector<int>& nums, int k) {
        int len = nums.size();
        int ans = len + 1;
        vector<long> presum(len + 1, 0);
        for (int i = 1; i <= len; ++i) {
            presum[i] = presum[i - 1] + nums[i - 1];
        }
        // store idx of num
        deque<int> deq;
        for (int i = 0; i <= len; ++i) {
            long cur = presum[i];
            // Since getting a interval shorter than (i - deq.front()) isn't possible anymore
            // so make deq.front() useless
            while (!deq.empty() && cur - presum[deq.front()] >= k) {
                ans = std::min(ans, i - deq.front());
                deq.pop_front();
            }
            // deq.back() can't make a shorter interval than cur, even there's a larger element after cur
            // so make deq.back() useless
            while (!deq.empty() && presum[deq.back()] >= cur) {
                deq.pop_back();
            }
            deq.push_back(i);
        }
        return ans > len ? -1 : ans;
    }
};