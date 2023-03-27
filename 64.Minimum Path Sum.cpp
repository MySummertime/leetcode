#include <vector>

using std::vector;


class Solution {
public:
    // dynamic programming && state compression
    int minPathSum(vector<vector<int>>& grid) {
        int h = grid.size(), w = grid[0].size();
        if (h == 1 && w == 1)   return grid[0][0];
        vector<int> dp(w, 0);
        dp[0] = grid[0][0];
        for (int j = 1; j < w; ++j) {
            dp[j] = dp[j - 1] + grid[0][j];
        }
        for (int i = 1; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (!j) dp[j] += grid[i][j];
                else    dp[j] = std::min(dp[j - 1], dp[j]) + grid[i][j];
            }
        }
        return dp[w - 1];
    }
};