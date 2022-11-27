#include <vector>

using std::vector;


class Solution {
public:
    // traversal
    bool check(vector<int>& nums) {
        int len = nums.size();
        int idx = 0;
        for (int i = 1; i < len; ++i) {
            if (nums[i] < nums[i - 1]) {
                idx = i;
                break;
            }
        }
        // if nums is a non-decreasing array, return true
        if (idx == 0)   return true;
        for (int i = idx + 1; i < len; ++i) {
            if (nums[i] < nums[i - 1]) {
                return false;
            }
        }
        return nums[0] >= nums[len - 1];
    }
};