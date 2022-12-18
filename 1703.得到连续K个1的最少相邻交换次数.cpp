#include <vector>

using std::vector;


class Solution {
public:
    // presum
    int minMoves(vector<int>& nums, int k) {
        vector<int> g;
        vector<int> presum(1, 0);
        for (int i = 0, len = nums.size(); i < len; ++i) {
            if (nums[i] == 1) {
                g.emplace_back(i - g.size());
                presum.emplace_back(presum.back() + g.back());
            }
        }
        int m = g.size(), ans = INT32_MAX;
        for (int i = 0, mid = i + k / 2; i <= m - k; ++i) {
            mid = i + k / 2;
            ans = std::min(ans, (1 - k % 2) * g[mid] + (presum[i + k] - presum[mid + 1]) - (presum[mid] - presum[i]));
        }
        return ans;
    }
};