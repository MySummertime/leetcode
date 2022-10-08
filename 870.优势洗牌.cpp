#include <vector>
#include <algorithm>
#include <numeric>

using std::vector;


class Solution {
public:
    // customized sort & greedy
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size();
        vector<int> id(len);
        vector<int> ans(len);
        std::sort(nums1.begin(), nums1.end(), std::less<>());
        // fills the range[first, last) with sequentially increasing values
        std::iota(id.begin(), id.end(), 0);
        // sort idxes by corresponding values of integers of nums2 ascendingly
        std::sort(id.begin(), id.end(), [&] (int i, int j) -> bool {
            return nums2[i] < nums2[j];
        });
        int l = 0, r = len - 1;
        for (const int& i : nums1) {
            if (i > nums2[id[l]]) {
                ans[id[l++]] = i;
            }
            else {
                ans[id[r--]] = i;
            }
        }
        return ans;
    }
};