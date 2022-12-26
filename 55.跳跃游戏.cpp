#include <vector>

using std::vector;


class Solution {
public:
    // greedy
    bool canJump(vector<int>& nums) {
        int sum = 0;
        for (int i = 0, len = nums.size(); i < len; ++i) {
            if (sum < i) return false;
            sum = std::max(sum, nums[i] + i);
        }
        return true;
    }
};