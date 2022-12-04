#include <vector>

using std::vector;


class Solution {
public:
    // 0-1 pack
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        vector<bool> can(2e4 + 1);
        for (int base : baseCosts) {
            can[base] = true;
        }
        toppingCosts.insert(toppingCosts.end(), toppingCosts.begin(), toppingCosts.end());
        for (int t : toppingCosts) {
            for (int i = 2e4; i >= t; --i) {
                can[i] = can[i] || can[i - t];
            }
        }
        int min_gap = INT32_MAX, ans = 0;
        for (int i = 1; i <= 2e4; ++i) {
            if (can[i] && std::abs(i - target) < min_gap) {
                ans = i;
                min_gap = std::abs(i - target);
            }
        }
        return ans;
    }
};