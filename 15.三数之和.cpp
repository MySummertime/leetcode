#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    // sort && two pointers
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        if (len < 3)    return {};
        std::sort(nums.begin(), nums.end(), std::less<>());
        vector<vector<int>> ans;
        for (int i = 0, l, r, sum; i < len; ++i) {
            if (nums[i] > 0)
                break;
            if (i && nums[i] == nums[i - 1])
                continue;
            // two pointers
            l = i + 1, r = len - 1, sum = 0;
            while (l < r) {
                sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[l + 1]) ++l;
                    while (l < r && nums[r] == nums[r - 1]) --r;
                    ++l;
                    --r;
                }
                else if (sum < 0) {
                    ++l;
                }
                else if (sum > 0) {
                    --r;
                }
            }
        }
        return ans;
    }
};