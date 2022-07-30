#include <vector>

/**
class Solution {
public:
    // presum
    int waysToSplit(std::vector<int>& nums) {
        int len = nums.size();
        std::vector<int> presum(1 + len, 0);
        for (int i = 1; i <= len; ++i) {
            presum[i] = presum[i - 1] + nums[i - 1];
        }
        int ans = 0;
        for (int i = 1, j = 1, k = 1; i < len - 1; ++i) {
            j = std::max(j, 1 + i);
            while (j < len && presum[j] < 2 * presum[i]) {
                ++j;
            }
            k = std::max(j, k);
            while (k < len && presum[k] - presum[i] <= presum[len] - presum[k]) {
                ++k;
            }
            ans = (ans + k - j) % mod;
        }
        return ans;
    }

private:
    static constexpr int mod = 1e9 + 7;
};
*/

class Solution {
public:
    // presum & binary search
    int waysToSplit(std::vector<int>& nums) {
        int len = nums.size();
        std::vector<int> presum(1 + len, 0);
        for (int i = 1; i <= len; ++i) {
            presum[i] = presum[i - 1] + nums[i - 1];
        }
        long long ans = 0;
        for (int i = 1; i < len - 1; ++i) {
            // find the scope of j:[left, right)
            int left = binarySearch(presum, 2 * presum[i], 1, len, true);
            int right = binarySearch(presum, presum.back() + presum[i] >> 1, 1, len, false);
            ans += std::max(0, std::min(right, len) - std::max(left, i + 1));
        }
        return int(ans % mod);
    }

private:
    int binarySearch(const std::vector<int>& presum, const int& target, int l, int r, const bool& flag = true) {
        while (l < r) {
            int m = l + ((r - l) >> 1);
            if (flag) {
                if (presum[m] < target) {
                    l = m + 1;
                }
                else {
                    r = m;
                }
            }
            else {
                if (presum[m] <= target) {
                    l = m + 1;
                }
                else {
                    r = m;
                }
            }
        }
        return r;
    }

private:
    static constexpr int mod = 1e9 + 7;
};