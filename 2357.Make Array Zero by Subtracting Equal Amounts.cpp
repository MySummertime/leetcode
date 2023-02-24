#include <vector>

using std::vector;


class Solution {
public:
    // hash map
    int minimumOperations(vector<int>& nums) {
        bool s[101] {};
        s[0] = true;
        int ans = 0;
        for (const int& i : nums) {
            if (!s[i]) {
                ++ans;
                s[i] = true;
            }
        }
        return ans;
    }
};