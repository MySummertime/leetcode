#include <vector>
#include <algorithm>
#include <numeric>

using std::vector;


class Solution {
public:
    int help(vector<int>& nums, int firstLen, int secondLen) {
        int suml = std::accumulate(nums.begin(), nums.begin() + firstLen, 0);
        int maxSumL = suml;
        int sumr = std::accumulate(nums.begin() + firstLen, nums.begin() + firstLen + secondLen, 0);
        int res = maxSumL + sumr;
        for (int i = firstLen + secondLen, j = firstLen; i < nums.size(); ++i, ++j) {
            suml += nums[j] - nums[j - firstLen];
            maxSumL = std::max(maxSumL, suml);
            sumr += nums[i] - nums[i - secondLen];
            res = std::max(res, maxSumL + sumr);
        }
        return res;
    }

    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        return std::max(help(nums, firstLen, secondLen), help(nums, secondLen, firstLen));
    }
};