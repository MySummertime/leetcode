#include <vector>

using std::vector;


class Solution {
public:
    // dynamic programming
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= target; ++j) {
                for (int p = 1; p <= k && j >= p; ++p) {
                    dp[i][j] = (dp[i - 1][j - p] + dp[i][j]) % MOD;
                }
            }
        }
        return dp[n][target];
    }

private:
    int MOD = 1e9 + 7;
};