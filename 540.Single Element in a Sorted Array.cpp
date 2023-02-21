#include <vector>

using std::vector;


class Solution_1 {
public:
    // bit manipulation
    int singleNonDuplicate(vector<int>& nums) {
        int ans = 0;
        for (const int& i : nums) {
            ans ^= i;
        }
        return ans;
    }
};


class Solution_2 {
public:
    // binary search && bit manipulation
    int singleNonDuplicate(vector<int>& nums) {
        int len = nums.size();
        int l = 0, r = len - 1, m;
        while (l < r) {
            m = l + ((r - l) >> 1);
            if (nums[m] == nums[m ^ 1]) {
                l = m + 1;
            }
            else {
                r = m;
            }
        }
        return nums[r];
    }
};