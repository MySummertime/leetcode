#include <vector>

using std::vector;


class Solution {
public:
    // math
    bool checkXMatrix(vector<vector<int>>& grid) {
        for (int i = 0, len = grid.size(); i < len; ++i) {
            for (int j = 0; j < len; ++j) {
                if (i == j || i + j + 1 == len) {
                    if (grid[i][j] == 0)
                        return false;
                }
                else if (grid[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
};