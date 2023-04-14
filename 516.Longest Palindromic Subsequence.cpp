#include <string>
#include <vector>

using std::string;
using std::vector;


class Solution {
public:
    // interval dynamic programming
    int longestPalindromeSubseq(string s) {
        int len = s.length();
        vector<vector<int>> dp(len, vector<int>(len));
        for (int i = 0; i < len; ++i)   dp[i][i] = 1;
        for (int i = 2; i <= len; ++i) {
            for (int l = 0, r; l + i - 1 < len; ++l) {
                r = l + i - 1;
                dp[l][r] = std::max(dp[l + 1][r], dp[l][r - 1]);
                dp[l][r] = std::max(dp[l][r], dp[l + 1][r - 1] + (s[l] == s[r] ? 2 : 0));
            }
        }
        return dp[0][len - 1];
    }
};