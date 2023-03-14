#include <vector>

using std::vector;


class Solution {
public:
    // math && greedy
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size(), n = colSum.size();
        vector<vector<int>> vec(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                vec[i][j] = std::min(rowSum[i], colSum[j]);
                rowSum[i] -= vec[i][j];
                colSum[j] -= vec[i][j];
            }
        }
        return vec;
    }
};