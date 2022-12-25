#include <vector>
#include <algorithm>

using std::vector;


class Solution {
public:
    // sort & prefix sum & binary search
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        std::sort(nums.begin(), nums.end(), std::less<>());
        int len = nums.size();
        // presum
        vector<int> presum(len, 0);
        presum[0] = nums[0];
        for (int i = 1; i < len; ++i) {
            presum[i] = presum[i - 1] + nums[i];
        }
        vector<int> ans;
        // binary search
        for (int i = 0, m = queries.size(); i < m; ++i) {
            int idx = binarySearch(presum, 0, len - 1, queries[i]);
            ans.emplace_back(idx == -1 ? 0 : idx + 1);
        }
        return ans;
    }

private:
    int binarySearch(const vector<int>& presum, int l, int r, const int& target) {
        int m;
        while (l < r) {
            m = l + ((r - l + 1) >> 1);
            if (presum[m] > target) {
                r = m - 1;
            }
            else {
                l = m;
            }
        }
        return presum[r] <= target ? r : -1;
    }
};