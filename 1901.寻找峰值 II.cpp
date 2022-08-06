#include <vector>

using std::vector;


class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int h = mat.size();
        int w = mat[0].size();
        int l = 0;  int r = w - 1;
        while (l <= r) {
            int max_row = 0;
            int mid_col = l + ((r - l) >> 1);
            for (int i = 0; i < h; ++i) {
                max_row = (mat[i][mid_col] >= mat[max_row][mid_col]) ? i : max_row;
            }
            bool left = (mid_col - 1 >= l) && (mat[max_row][mid_col - 1] > mat[max_row][mid_col]);
            bool right = (mid_col + 1 <= r) && (mat[max_row][mid_col] < mat[max_row][mid_col + 1]);
            // found the peak element
            if (!left && !right) {
                return {max_row, mid_col};
            }
            // peak element is at the right side of mid_col
            else if (right) {
                l = mid_col + 1;
            }
            // peak element is at the left side of mid_col
            else {
                r = mid_col - 1;
            }
        }
        return {-1, -1};
    }
};