#include <vector>
#include <string>

using std::vector;
using std::string;


class Solution {
public:
    // KMP
    bool repeatedSubstringPattern(string s) {
        int len = s.length();
        if (!len)   return false;
        vector<int> next(len, 0);
        getNext(next, s);
        for (int i = 0; i < len; ++i) {
            if (next.back() && (len % (len - next.back())) == 0) {
                return true;
            }
        }
        return false;
    }

private:
    void getNext(vector<int>& next, const string& s) {
        for (int i = 1, j = 0, len = s.length(); i < len; ++i) {
            // maintain the same prefix length
            while (j && s[i] != s[j]) {
                j = next[j - 1];
            }
            // update the longest prefix length
            if (s[i] == s[j]) {
                ++j;
            }
            next[i] = j;
        }
    }
};