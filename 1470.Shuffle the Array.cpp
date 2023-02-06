#include <vector>

using std::vector;


class Solution {
public:
    // two pointers
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2 * n);
        for (int i = 0, l = 0, r = n; r < 2 * n; i += 2) {
            ans[i] = nums[l++];
            ans[i + 1] = nums[r++];
        }
        return ans;
    }
};