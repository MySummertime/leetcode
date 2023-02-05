#include <vector>
#include <string>

using std::vector;
using std::string;


class Solution {
public:
    // sliding window
    vector<int> findAnagrams(string s, string p) {
        vector<int> mp1(26, 0);
        vector<int> mp2(26, 0);

        int slen = s.length(), plen = p.length();
        for (int i = 0; i < plen; ++i) {
            ++mp1[p[i] - 'a'];
        }

        vector<int> ans;
        int l = 0, r = 0;
        while (r < slen) {
            ++mp2[s[r] - 'a'];
            if (r >= plen)  --mp2[s[l++] - 'a'];
            if (mp1 == mp2) ans.push_back(r - plen + 1);
            ++r;
        }
        return ans;
    }
};