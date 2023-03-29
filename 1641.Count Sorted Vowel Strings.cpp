#include <vector>
#include <numeric>

using std::vector;


class Solution {
public:
    // dynamic programming
    int countVowelStrings(int n, const int& cnt = 5) {
        vector<int> dp(cnt, 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < cnt; ++j) {
                dp[j] += dp[j - 1];
            }
        }
        return std::accumulate(dp.begin(), dp.end(), 0);
    }
};