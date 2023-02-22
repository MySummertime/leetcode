#include <vector>

using std::vector;


class Solution {
public:
    // binary search
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 0, r = 0;
        for (const int& i : weights) {
            l = std::max(l, i);
            r += i;
        }
        int m, ans = r;
        while (l <= r) {
            m = l + ((r - l) >> 1);
            if (check(weights, days, m)) {
                ans = m;
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return ans;
    }

private:
    bool check(const vector<int>& weight, int days, int capacity) {
        int dcnt = 1;
        int wsum = 0;
        for (const int& i : weight) {
            if (wsum + i > capacity) {
                ++dcnt;
                wsum = 0;
            }
            wsum += i;
        }
        return dcnt <= days;
    }
};