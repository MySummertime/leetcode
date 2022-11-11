#include <vector>

using std::vector;


class Solution {
public:
    // two pointers
    int removeDuplicates(vector<int>& nums) {
        if (!nums.size())   return 0;
        int l = 0;
        for (int r = 1, len = nums.size(); r < len; ++r) {
            if (nums[l] != nums[r]) {
                if (l + 1 < r) {
                    nums[l + 1] = nums[r];
                }
                ++l;
            }
        }
        return l + 1;
    }
};