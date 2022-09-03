#include <vector>
#include <algorithm>

using std::vector;


class Solution {
public:
    // sort & greedy
    int findLongestChain(vector<vector<int>>& pairs) {
        std::sort(pairs.begin(), pairs.end(), [&] (vector<int>& a, vector<int>& b) -> bool {
            if (a[1] == b[1])   return a[0] < b[0];
            return a[1] < b[1];
        });
        int ans = 0, cur = INT32_MIN;
        for (const vector<int>& vec : pairs) {
            if (cur < vec[0]) {
                cur = vec[1];
                ++ans;
            }
        }
        return ans;
    }
};