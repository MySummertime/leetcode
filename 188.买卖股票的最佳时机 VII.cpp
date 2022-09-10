#include <vector>

using std::vector;


class Solution {
public:
    // dynamic programming
    // time: O(nk); memory: O(nk)
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        if (!len)   return 0;
        if (k >= (len >> 1)) {
            return getProfit(prices);
        }
        // dp[i][0]: profit if sell a stock
        // dp[i][1]: profit if have a stock
        vector<vector<int>> dp(k + 1, vector<int>(2, 0));
        for (int i = 1; i <= k; ++i) {
            dp[i][0] = 0;
            dp[i][1] = -prices[0];
        }
        for (int i = 1; i < len; ++i) {
            for (int j = k; j; --j) {
                dp[j][0] = std::max(dp[j][0], dp[j][1] + prices[i]);
                dp[j][1] = std::max(dp[j][1], dp[j - 1][0] - prices[i]);
            }
        }
        return dp[k][0];
    }

private:
    // time: O(n); memory: O(1)
    int getProfit(vector<int>& prices) {
        int len = prices.size();
        if (len < 2)    return 0;
        int sell = 0;
        int have = -prices[0];
        for (int i = 1, new_sell, new_have; i < len; ++i) {
            new_sell = std::max(sell, have + prices[i]);
            new_have = std::max(have, sell - prices[i]);
            sell = new_sell;
            have = new_have;
        }
        return sell;
    }
};