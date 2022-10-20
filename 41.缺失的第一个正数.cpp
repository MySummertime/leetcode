#include <vector>

using std::vector;


class Solution {
public:
    // hash in-place
    // time: O(len), space: O(1)
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            while (nums[i] != i + 1) {
                if (nums[i] <= 0 || nums[i] > len || nums[i] == nums[nums[i] - 1]) {
                    break;
                }
                mySwap(nums, i, nums[i] - 1);
            }
        }
        for (int i = 0; i < len; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return nums.size() + 1;
    }

private:
    inline void mySwap(vector<int>& vec, int i, int j) {
        int tmp = vec[i];
        vec[i] = vec[j];
        vec[j] = tmp;
    }
};