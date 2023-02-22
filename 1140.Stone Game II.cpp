#include <vector>
#include <numeric>

using std::vector;


class Solution {
public:
    // dynamic programming
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        dp.resize(128, vector<int>(256));
        int sum = std::accumulate(piles.begin(), piles.end(), 0);
        int diff = solve(piles, 0, 1);
        return (sum + diff) >> 1;
    }

    int solve(vector<int> piles, int i, int M) {
        if (i >= piles.size())  return 0;
        if (dp[i][M] != 0) return dp[i][M];

        int total = 0, ans = INT_MIN;
        for (int j = 0; j < 2 * M; ++j) {
            if (i + j < piles.size())
                total += piles[i+j];
            ans = std::max(ans, total - solve(piles, i + j + 1, std::max(M, j + 1)));
        }
        return dp[i][M] = ans;
    }

private:
    vector<vector<int>> dp;
};