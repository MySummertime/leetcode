#include <vector>

using std::vector;

class Solution {
public:
    // simulate
    int numSpecial(vector<vector<int>>& mat) {
        int h = mat.size(), w = mat[0].size();
        for (int i = 0; i < h; ++i) {
            // count the frequency of 1 in each column
            int cnt = 0;
            for (int j = 0; j < w; ++j) {
                if (mat[i][j] == 1) {
                    ++cnt;
                }
            }
            if (!i) --cnt;
            // record the frequency of 1 in each column at the first row
            if (cnt) {
                for (int j = 0; j < w; ++j) {
                    if (mat[i][j] == 1) {
                        mat[0][j] += cnt;
                    }
                }
            }
        }
        // traverse the first row to get the quantity of each special element
        int ans = 0;
        for (const int& i : mat[0]) {
            if (i == 1)  ++ans;
        }
        return ans;
    }
};