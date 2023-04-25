#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using std::vector;
using std::string;


class Solution {
public:
    // hash map
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int len = heights.size();
        vector<int> mp(len);
        std::iota(mp.begin(), mp.end(), 0);
        std::sort(mp.begin(), mp.end(), [&] (int a, int b) -> bool {
            return heights[a] > heights[b];
        });
        vector<string> ans(len);
        for (int i = 0; i < len; ++i) {
            ans[i] = names[mp[i]];
        }
        return ans;
    }
};