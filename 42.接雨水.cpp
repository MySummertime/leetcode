#include <vector>

using std::vector;


class Solution {
public:
    // two pointers
    int trap(vector<int>& height) {
        int len = height.size();
        int ans = 0;
        int l = 0, r = len - 1;
        int lmax = 0, rmax = 0;
        while (l < r) {
            lmax = std::max(lmax, height[l]);
            rmax = std::max(rmax, height[r]);
            if (lmax < rmax) {
                ans += lmax - height[l++];
            }
            else {
                ans += rmax - height[r--];
            }
        }
        return ans;
    }
};