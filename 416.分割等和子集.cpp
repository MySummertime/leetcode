#include <vector>
#include <numeric>

using std::vector;


class Solution {
public:
    // dynamic programming
    // 0-1 package & existence
    bool canPartition(vector<int>& nums) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1)    return false;
        int target = sum >> 1;
        vector<bool> dp(target + 1, 0);
        dp[0] = 1;
        for (const int& num : nums) {
            for (int i = target; i >= num; --i) {
                dp[i] = dp[i] || dp[i - num];
            }
        }
        return dp[target];
    }
};