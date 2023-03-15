#include <vector>

using std::vector;


class Solution {
public:
    // enumerate
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<bool>> matrix(n, vector<bool>(n, false));
        vector<int> degree(n, 0);
        for (const vector<int>& r : roads) {
            matrix[r[0]][r[1]] = true;
            matrix[r[1]][r[0]] = true;
            ++degree[r[0]];
            ++degree[r[1]];
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int cur = degree[i] + degree[j] - (matrix[i][j] ? 1 : 0);
                ans = std::max(ans, cur);
            }
        }
        return ans;
    }
};