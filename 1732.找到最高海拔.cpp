#include <vector>
#include <algorithm>

using std::vector;


class Solution {
public:
    // simulate
    int largestAltitude(vector<int>& gain) {
        int cur = 0, ans = 0;
        for (const int& i : gain) {
            cur += i;
            ans = std::max(cur, ans);
        }
        return ans;
    }
};