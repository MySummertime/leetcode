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
        for (int i = 0; i < len; ++i) {
            dp[i] = players[i].second;
            for (int j = 0; j < i; ++j) {
                if (players[j].second <= players[i].second) {
                    dp[i] = std::max(dp[i], dp[j] + players[i].second);
                }
            }
            ans = ans > dp[i] ? ans : dp[i];
        }
        return ans;
    }
};