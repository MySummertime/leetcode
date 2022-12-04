#include <vector>

using std::vector;


class Solution {
public:
    // presum
    int minimumAverageDifference(vector<int>& nums) {
        long long left(0), right(0);
        for (const int& i : nums) {
            right += i;
        }
        int idx;
        for (int i = 0, len(nums.size()), dif(INT32_MAX), a, b; i < len; ++i) {
            left += nums[i];
            right -= nums[i];
            a = left / (i + 1);
            b = (i == len - 1) ? 0 : right / (len - i - 1);
            if (std::abs(a - b) < dif) {
                dif = std::abs(a - b);
                idx = i;
            }
        }
        return idx;
    }
};