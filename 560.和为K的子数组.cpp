#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;


class Solution {
public:
    // presum & hash map
    // time: O(n), space: O(n)
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp {{0, 1}};
        int presum = 0;
        int ans = 0;
        for (const int& i : nums) {
            presum += i;
            ans += mp[presum - k];
            ++mp[presum];
        }
        return ans;
    }
};


/*
class Solution {
public:
    // presum & brutal force
    // time: O(n ^ 2), space: O(1)
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        for (int r = 0, len = nums.size(), presum; r < len; ++r) {
            presum = 0;
            for (int l = r; l >= 0; --l) {
                presum += nums[l];
                if (presum == k) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};
*/