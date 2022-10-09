#include <vector>

using std::vector;


class Solution {
public:
    // presum
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> ans(len, 1);
        // store the prefixes in the answer vector
        for (int i = 1; i < len; ++i) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }
        // constant extra space
        int suffix = 1;
        for (int i = len - 1; i >= 0; --i) {
            ans[i] *= suffix;
            // multiply suffixes to existing products
            suffix *= nums[i];
        }
        return ans;
    }
};