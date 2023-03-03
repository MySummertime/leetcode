#include <string>
#include <vector>

using std::string;
using std::vector;


class Solution {
public:
    // KMP
    int strStr(string s, string p) {
        int slen = s.length();
        int plen = p.length();
        if (!plen) {
            return 0;
        }
        // set dummy head
        s.insert(s.begin(), ' ');
        p.insert(p.begin(), ' ');
        vector<int> next(1 + plen, 0);
        // gain the next vector
        for (int i = 2, j = 0; i <= plen; ++i) {
            while (j && p[i] != p[j + 1]) {
                j = next[j];
            }
            if (p[i] == p[j + 1]) {
                ++j;
            }
            next[i] = j;
        }
        // match
        for (int i = 1, j = 0; i <= slen; ++i) {
            while (j && s[i] != p[j + 1]) {
                j = next[j];
            }
            if (s[i] == p[j + 1]) {
                ++j;
            }
            if (j == plen) {
                return i - plen;
            }
        }
        return -1;
    }
};