#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    // binary search
    int bagOfTokensScore(vector<int>& tokens, int power) {
        std::sort(tokens.begin(), tokens.end(), std::less<>());
        int l = 0, r = tokens.size() - 1;
        int ans = 0;
        while (l <= r) {
            if (power >= tokens[l]) {
                ++ans;
                power -= tokens[l];
                ++l;
            }
            else {
                if (ans && r - l > 1) {
                    --ans;
                    power += tokens[r];
                    --r;
                }
                else {
                    break;
                }
            }
        }
        return ans;
    }
};