#include <vector>
#include <functional>
#include <iostream>

using std::vector;
using std::function;


class Solution {
public:
    // dynamic programming
    int minScoreTriangulation(vector<int>& values) {
        int len = values.size();
        vector<vector<int>> vis(len, vector<int>(len, -1));

        function<int(int, int)> dfs = [&] (int i, int j) -> int {
            if (i + 1 == j) return 0;
            int &ans = vis[i][j];
            if (ans != -1)  return ans;
            ans = INT32_MAX;
            for (int k = i + 1; k < j; ++k) {
                ans = std::min(ans, dfs(i, k) + dfs(k, j) + values[i] * values[j] * values[k]);
            }
            return ans;
        };

        return dfs(0, len - 1);
    }
};