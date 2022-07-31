#include <vector>
#include <algorithm>

class Solution {
public:
    // binary search
    std::vector<int> findRightInterval(std::vector<std::vector<int>>& intervals) {
        int len = intervals.size();
        // clone: {start, idx}
        std::vector<std::vector<int>> clone(len, std::vector<int>(2, 0));
        for (int i = 0; i < len; ++i) {
            clone[i] = {intervals[i][0], i};
        }
        std::sort(clone.begin(), clone.end());
        std::vector<int> ans(len, -1);
        for (int i = 0; i < len; ++i) {
            int idx = binarySearch(intervals, clone, 0, len - 1, i);
            if (clone[idx][0] < intervals[i][1]) {
                continue;
            }
            ans[i] = clone[idx][1];
        }
        return ans;
    }

private:
    int binarySearch(std::vector<std::vector<int>>& intervals, std::vector<std::vector<int>>& clone,
    int l, int r, const int& idx) {
        while (l < r) {
            int m = l + ((r - l) >> 1);
            if (clone[m][0] >= intervals[idx][1]) {
                r = m;
            }
            else {
                l = m + 1;
            }
        }
        return r;
    }
};