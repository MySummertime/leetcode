#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;


class Solution {
public:
    // sliding window
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int l = 0, r = 0, len = nums.size(); r < len; ++r) {
            if (mp.find(nums[r]) != mp.end() && r - mp[nums[r]] <= k) {
                return true;
            }
            mp[nums[r]] = r;
        }
        return false;
    }
};