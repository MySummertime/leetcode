#include <vector>

using std::vector;


class Solution {
public:
    // two pointers
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = nums.size(), ans = len + 1;
        int l = 0, r = 0;
        for (int cur = 0; r < len; ++r) {
            cur += nums[r];
            while (cur - nums[l] >= target) {
                cur -= nums[l++];
            }
            if (cur >= target) {
                ans = std::min(ans, r - l + 1);
            }
        }
        return ans <= len ? ans : 0;
    }
};