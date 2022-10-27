#include <vector>

using std::vector;


class Solution {
public:
    // dynamic programming
    int numSquares(int n) {
        vector<int> dp(n + 1, 0x3f3f3f3f);
        dp[0] = 0;
        for (int i = 1, cur; i * i <= n; ++i) {
            cur = i * i;
            for (int j = cur; j <= n; ++j) {
                dp[j] = std::min(dp[j], dp[j - cur] + 1);
            }
        }
        return dp[n];
    }
};


// timeout
/*
class Solution {
public:
    // dynamic programming
    int numSquares(int n) {
        // get all of the possible perfect square numbers
        vector<int> vec;
        int idx = 1;
        while (idx * idx <= n) {
            vec.push_back(idx * idx);
            ++idx;
        }
        int len = vec.size();
        vector<vector<int>> dp(len + 1, vector<int>(n + 1, 0x3f3f3f3f));
        dp[0][0] = 0;
        for (int i = 1, prev; i <= len; ++i) {
            prev = vec[i - 1];
            for (int j = 0; j <= n; ++j) {
                // don't choose the current value
                dp[i][j] = dp[i - 1][j];
                // choose the current value by [1, k] times
                for (int k = 1; k * prev <= j; ++k) {
                    if (dp[i - 1][j - k * prev] != 0x3f3f3f3f) {
                        dp[i][j] = std::min(dp[i][j], dp[i - 1][j - k * vec[i - 1]] + k);
                    }
                }
            }
        }
        return dp[len][n];
    }
};
*/