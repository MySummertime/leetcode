#include <vector>

using std::vector;


class Solution {
public:
    // simulate
    int arraySign(vector<int>& nums) {
        int ans = 1;
        for (const int& i : nums) {
            if (i == 0) return 0;
            if (i < 0)  ans *= -1;
        }
        return ans;
    }
};