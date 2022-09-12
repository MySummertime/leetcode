#include <vector>
#include <utility>
#include <algorithm>

using std::vector;


class Solution {
public:
    // binary search
    int specialArray(vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), std::less<>());
        int len = nums.size();
        int l = 1;
        int r = (len < nums[len - 1]) ? len : nums[len - 1];
        return binarySearch(nums, l, r);
    }

private:
    int binarySearch(const vector<int>& vec, int l, int r) {
        int m, cnt;
        while (l < r) {
            m = l + ((r - l) >> 1);
            cnt = countElements(vec, m);
            if (cnt == m)   return m;
            else if (cnt > m) {
                l = m + 1;
            }
            else {
                r = m;
            }
        }
        return countElements(vec, l) == l ? l : -1;
    }

    int countElements(const vector<int>& vec, const int& target) {
        int ans = 0;
        for (const int& i : vec) {
            if (i >= target) {
                ++ans;
            }
        }
        return ans;
    }
};