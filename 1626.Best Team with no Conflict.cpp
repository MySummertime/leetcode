#include <vector>
#include <algorithm>

using std::vector;


class Solution {
public:
    // dynamic programming
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int len = scores.size();
        vector<std::pair<int, int>> players;
        for (int i = 0; i < len; ++i) {
            players.emplace_back(ages[i], scores[i]);
        }
        std::sort(players.begin(), players.end(), std::less<>());

        vector<int> dp(len);    // the score of the person at each index
        int ans = 0;
        for (int r = 0; r < len; ++r) {
            dp[r] = players[r].second;
            for (int l = 0; l < r; ++l) {
                if (players[l].second <= players[r].second) {
                    dp[r] = std::max(dp[r], dp[l] + players[r].second);
                }
            }
            ans = ans > dp[r] ? ans : dp[r];
        }
        return ans;
    }
};