#include <vector>
#include <iostream>

using std::vector;


class Solution {
public:
    // dynamic programming
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int len = days.size();
        vector<int> dp(len + 1, INT32_MAX);
        dp[0] = 0;
        for (int i = 1, j; i <= len; ++i) {
            dp[i] = dp[i - 1] + costs[0];
            j = i - 1;
            while (j >= 0 && days[i - 1] - days[j] < 7) {
                --j;
            }
            dp[i] = std::min(dp[i], dp[j + 1] + costs[1]);
            j = i - 1;
            while (j >= 0 && days[i - 1] - days[j] < 30) {
                --j;
            }
            dp[i] = std::min(dp[i], dp[j + 1] + costs[2]);
        }
        return dp[len];
    }
};