#include <vector>

using std::vector;


class Solution {
public:
    // two pointers
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int ans = 0, a = -1, b = -1;
        for (int i = 0, len = nums.size(); i < len; ++i) {
            if (nums[i] > right)    a = i;
            if (nums[i] >= left)    b = i;
            ans += b - a;
        }
        return ans;
    }
};