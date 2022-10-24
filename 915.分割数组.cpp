#include <vector>

using std::vector;


class Solution {
public:
    // traversal twice
    int partitionDisjoint(vector<int>& nums) {
        int len = nums.size();
        vector<int> min_vec(len);
        min_vec[len - 1] = nums[len - 1];
        for (int i = len - 2; i >= 0; --i) {
            min_vec[i] = std::min(nums[i], min_vec[i + 1]);
        }
        int max_val = INT32_MIN;
        for (int i = 0; i < len; ++i) {
            max_val = std::max(max_val, nums[i]);
            if (max_val <= min_vec[i + 1]) {
                return i + 1;
            }
        }
        return len - 1;
    }
};