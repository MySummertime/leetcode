#include <cstring>



class Solution {
public:
    // simulate
    double champagneTower(int poured, int query_row, int query_glass) {
        std::memset(vec, 0, sizeof(vec));
        vec[0][0] = poured;
        for (int i = 0; i < 100; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (vec[i][j] > 1.0) {
                    double excess = vec[i][j] - 1.0;
                    vec[i][j] = 1.0;
                    vec[i + 1][j] += excess / 2.0;
                    vec[i + 1][j + 1] += excess / 2.0;
                }
            }
        }
        return vec[query_row][query_glass];
    }

private:
    double vec[105][105];
};