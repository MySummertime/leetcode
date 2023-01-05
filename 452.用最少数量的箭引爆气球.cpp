#include <vector>
#include <algorithm>

using std::vector;


class Solution {
public:
    // interval dynamic programming
    int findMinArrowShots(vector<vector<int>>& points) {
        // sort the array by the second element
        std::sort(points.begin(), points.end(), [&] (const vector<int>& a, const vector<int>& b) -> bool {
            return a[1] < b[1];
        });
        int ans = 1;
        int prev = points[0][1];
        for (int i = 1, len = points.size(); i < len; ++i) {
            if (points[i][0] > prev) {
                prev = points[i][1];
                ++ans;
            }
        }
        return ans;
    }
};