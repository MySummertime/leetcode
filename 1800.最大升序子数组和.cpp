#include <vector>

using std::vector;

class Solution {
public:
    // simulate
    int maxAscendingSum(vector<int>& nums) {
        int ans = nums[0];
        for (int i = 0, len = nums.size(), cur = nums[0]; i < len - 1; ++i) {
            if (nums[i + 1] > nums[i]) {
                cur += nums[i + 1];
            }
            else {
                cur = nums[i + 1];
            }
            ans = ans > cur ? ans : cur;
        }
        return ans;
    }
};