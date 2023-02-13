#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;


class Solution {
public:
    // sliding window
    int balancedString(string s) {
        unordered_map<char, int> mp;
        for (const char& ch : s) {
            ++mp[ch];
        }
        int len = s.length(), m = len / 4;
        if (mp['Q'] == m && mp['W'] == m && mp['E'] == m && mp['R'] == m) {
            return 0;
        }
        int ans = len;
        for (int left = 0, right = 0; right < len; ++right) {
            --mp[s[right]];
            while (left < len && mp['Q'] <= m && mp['W'] <= m && mp['E'] <= m && mp['R'] <= m) {
                ans = std::min(ans, right - left + 1);
                ++mp[s[left++]];
            }
        }
        return ans;
    }
};
