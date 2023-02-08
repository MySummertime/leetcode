#include <vector>

using std::vector;


class Solution {
public:
    // greedy
    int jump(vector<int>& nums) {
        int ans = 0;
        for (int i = 0, farest = 0, end = 0, len = nums.size(); i < len - 1; ++i) {
            farest = std::max(farest, i + nums[i]);
            if (i == end) {
                end = farest;
                ++ans;
            }
        }
        return ans;
    }
};