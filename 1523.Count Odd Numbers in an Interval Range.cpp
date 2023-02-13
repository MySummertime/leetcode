

class Solution {
public:
    // math
    int countOdds(int low, int high) {
        int ans = (high - low) >> 1;
        if (low & 1 || high & 1) {
            ++ans;
        }
        return ans;
    }
};