#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;


class Solution {
public:
    // counting
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (const int& i : nums)   ++mp[i];
        int cnt = 0, leftover = 0;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            cnt += it->second / 2;
            leftover += it->second % 2;
        }
        return {cnt, leftover};
    }
};