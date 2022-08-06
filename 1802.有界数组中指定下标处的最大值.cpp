#include <algorithm>

using std::max;
using std::min;


class Solution {
public:
    // double pointers
    int maxValue(int n, int index, int maxSum) {
        int l = index; int r = index;
        int dif = maxSum - n;
        int ans = 1;
        int dl = 0;   int dr = 0;
        while (dif > 0) {
            // haven't reach left bound
            if (--l >= 0) {
                ++dl;
            }
            // haven't reach right bound
            if (++r < n) {
                ++dr;
            }
            // reach both left & right bound
            if (l < 0 && r >= n) {
            ans += dif % n == 0 ? dif / n : dif / n + 1;
            return ans;
            }
            ++ans;
            dif -= dl + dr + 1;
        }
        return ans;
    }
};