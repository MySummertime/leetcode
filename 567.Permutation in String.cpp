#include <string>
#include <vector>

using std::string;
using std::vector;


class Solution {
public:
    // sliding window && hash map
    bool checkInclusion(string s1, string s2) {
        int llen = s1.length(), rlen = s2.length();
        if (llen > rlen)    return false;
        vector<int> mp1(26, 0);
        vector<int> mp2(26, 0);
        for (int i = 0; i < llen; ++i) {
            ++mp1[s1[i] - 'a'];
        }
        int l = 0, r = 0;
        while (r < rlen) {
            ++mp2[s2[r] - 'a'];
            if (r >= llen)  --mp2[s2[l++] - 'a'];
            if (mp2 == mp1) return true;
            ++r;
        }
        return false;
    }
};