#include <vector>

using std::vector;


class Solution {
public:
    // dynamic programming
    // time: O(n), memory: O(1)
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (!len)   return 0;
        int same = 0, buy = -prices[0];
        for (int i = 1; i < len; ++i) {
            same = std::max(same, buy + prices[i]);
            buy = std::max(buy, -prices[i]);
        }
        return same;
    }
};