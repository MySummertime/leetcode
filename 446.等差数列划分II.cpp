typedef long long ll;

#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;


class Solution {
public:
    // dynamic programming
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0;
        int len = nums.size();
        vector<unordered_map<ll, int>> dp(len);
        for (int i = 1; i < len; ++i) {
            for (int j = 0; j < i; ++j) {
                ll diff = (ll)nums[i] - nums[j];
                if (diff > INT32_MAX || diff < INT32_MIN)
                    continue;
                dp[i][diff] += dp[j][diff] + 1;
                ans += dp[j][diff];
            }
        }
        return ans;
    }
};