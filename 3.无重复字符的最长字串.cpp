#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;


class Solution {
public:
    // two pointers
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int l = 0, r = 0;
        unordered_map<char, int> mp;
        for (int len = s.length(); r < len; ++r) {
            ++mp[s[r]];
            while (mp[s[r]] > 1) {
                --mp[s[l++]];
            }
            ans = std::max(ans, r - l + 1);
        }
        return ans;
    }
};