#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    // The Pigeon-hole Principle
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i = 0, len = nums.size(); i < len; ++i) {
            while (nums[nums[i] - 1] != nums[i]) {
                mySwap(nums, i, nums[i] - 1);
            }
        }
        vector<int> ans;
        for (int i = 0, len = nums.size(); i < len; ++i) {
            if (nums[i] != i + 1) {
                ans.emplace_back(i + 1);
            }
        }
        return ans;
    }

private:
    void mySwap(vector<int>& nums, int idx1, int idx2) {
        if (idx1 == idx2)   return;
        nums[idx1] ^= nums[idx2];
        nums[idx2] ^= nums[idx1];
        nums[idx1] ^= nums[idx2];
    }
};