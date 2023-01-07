#include <vector>
#include <numeric>

using std::vector;


class Solution1 {
public:
    // two pointers
    int minOperations(vector<int>& nums, int x) {
        int target = std::accumulate(nums.begin(), nums.end(), 0) - x;
        if (target < 0) return -1;

        int ans = -1, len = nums.size();
        for (int l = 0, r = 0, cur = 0; r < len; ++r) {
            cur += nums[r];
            while (cur > target) cur -= nums[l++];
            if (cur == target)   ans = std::max(ans, r - l + 1);
        }
        return ans < 0 ? -1 : len - ans;
    }
};
