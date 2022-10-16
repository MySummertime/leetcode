#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;


class Solution {
public:
    // bottom-up dynamic programming
    // time: O(len * len * D)
    // space: O(n)
    int minDifficulty(vector<int>& arr, int D) {
        int len = arr.size();
        if (len < D)  return -1;
        vector<int> dp(len + 1, INF);
        dp[len] = 0;
        // traverse the rod
        for (int d = 1; d <= D; ++d) {
            // traverse the arr
            // i: current idx, while j: idx of next max
            for (int i = 0, maxd; i <= len - d; ++i) {
                maxd = 0;
                dp[i] = INF;
                for (int j = i; j <= len - d; ++j) {
                    maxd = std::max(maxd, arr[j]);
                    dp[i] = std::min(dp[i], maxd + dp[j + 1]);
                }
            }
        }
        return dp[0];
    }

private:
    static constexpr int INF = 1e9;
};