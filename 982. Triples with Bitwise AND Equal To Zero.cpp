#include <vector>

using std::vector;


class Solution {
public:
    int countTriplets(vector<int> &nums) {
        int cnt[1 << 16] {};
        for (int x : nums)
            for (int y : nums)
                ++cnt[x & y];
        int ans = 0;
        for (int x : nums)
            for (int y = 0; y < 1 << 16; ++y)
                if ((x & y) == 0)
                    ans += cnt[y];
        return ans;
    }
};
