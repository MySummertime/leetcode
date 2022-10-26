#include <vector>
#include <unordered_set>

using std::vector;
using std::unordered_set;


class Solution {
public:
    // presum
    // time: O(n), space: O(n)
    bool checkSubarraySum(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> presum(len + 1, 0);
        for (int i = 1; i <= len; ++i) {
            presum[i] = presum[i - 1] + nums[i - 1];
        }
        unordered_set<int> st;
        for (int i = 2; i <= len; ++i) {
            st.insert(presum[i - 2] % k);
            if (st.find(presum[i] % k) != st.end()) {
                return true;
            }
        }
        return false;
    }
};