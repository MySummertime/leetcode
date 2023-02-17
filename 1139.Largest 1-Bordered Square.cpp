#include <vector>

using std::vector;


class Solution {
public:
    // presum
    int largest1BorderedSquare(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> rs(m, vector<int>(n + 1)), cs(n, vector<int>(m + 1));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                rs[i][j + 1] = rs[i][j] + grid[i][j];   // presum for each row
                cs[j][i + 1] = cs[j][i] + grid[i][j];   // presum for each column
            }
        for (int d = std::min(m, n); d; --d)
            for (int i = 0; i <= m - d; ++i)
                for (int j = 0; j <= n - d; ++j)
                    if (rs[i][j + d] - rs[i][j] == d && // up
                        cs[j][i + d] - cs[j][i] == d && // down
                        rs[i + d - 1][j + d] - rs[i + d - 1][j] == d && // left
                        cs[j + d - 1][i + d] - cs[j + d - 1][i] == d)   // right
                        return d * d;
        return 0;
    }
};