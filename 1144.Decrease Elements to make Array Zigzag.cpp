#include <vector>
#include <iostream>

using std::vector;


class Solution {
public:
    // greedy
    int movesToMakeZigzag(vector<int>& nums) {
        int oddsum = 0, evensum = 0;
        for(int i = 0, len = nums.size(); i < len; ++i) {
            if (i % 2 == 0) {
                int left = i == 0 ? INT_MAX : nums[i - 1];
                int right = i == len - 1 ? INT_MAX : nums[i + 1];
                evensum += std::max(nums[i] - (std::min(left, right) - 1), 0);
            }
            else {
                int left = i == 0 ? INT_MAX : nums[i - 1];
                int right = i == len - 1 ? INT_MAX : nums[i + 1];
                oddsum += std::max(nums[i] - (std::min(left, right) - 1), 0);
            }
        }
        return std::min(oddsum, evensum);
    }
};