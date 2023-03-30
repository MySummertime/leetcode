#include <vector>
#include <algorithm>

using std::vector;


class Solution {
public:
    // customized sort
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        std::sort(points.begin(), points.end(), std::less<>());
        int ans = 0;
        for (int i = 1, len = points.size(); i < len; ++i) {
            ans = std::max(points[i][0] - points[i - 1][0], ans);
        }
        return ans;
    }
};