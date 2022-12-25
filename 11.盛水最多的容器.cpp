#include <vector>

using std::vector;


class Solution {
public:
    // two pointers
    // time: O(n); space: O(1)
    int maxArea(vector<int>& height) {
        int len = height.size();
        int ans = 0;
        int l = 0, r = len - 1;
        while (l < r) {
            ans = std::max(ans, (r - l) * std::min(height[l], height[r]));
            height[l] < height[r] ? ++l : --r;
        }
        return ans;
    }
};