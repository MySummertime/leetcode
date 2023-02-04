#include <vector>
#include <algorithm>

using std::vector;


class Solution {
public:
    // sort
    int getMaximumConsecutive(vector<int>& coins) {
        int ans = 0;
        std::sort(coins.begin(), coins.end(), std::less<>());
        for (const int& i : coins) {
            if (ans + 1 < i) {
                break;
            }
            ans += i;
        }
        // 0 is also an integer
        return ans + 1;
    }
};