#include <vector>

using std::vector;


class Solution {
public:
    // two pointers
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int ans = 0;
        int l = 0, r = 0;
        long long prod = 1;
        for (int len = nums.size(); r < len; ++r) {
            prod *= nums[r];
            while (prod >= k) {
                prod /= nums[l++];
            }
            ans += r - l + 1;
        }
        return ans;
    }
};