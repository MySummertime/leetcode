#include <vector>
#include <string>

using std::vector;
using std::string;


class Solution {
public:
    // two pointers
    int expressiveWords(string s, vector<string>& words) {
        int ans = 0;
        for (const string& word : words) {
            if (check(s, word)) {
                ++ans;
            }
        }
        return ans;
    }

private:
    bool check(const string& s, const string& word) {
        int l = 0, r = 0;
        while (l < s.length() && r < word.length()) {
            if (s[l] != word[r])    return false;
            char ch = s[l];
            int cntl = 0;
            while (l < s.length() && s[l] == ch) {
                ++cntl;
                ++l;
            }
            int cntr = 0;
            while (r < word.length() && word[r] == ch) {
                ++cntr;
                ++r;
            }
            if (cntl < cntr)    return false;
            if (cntl != cntr&& cntl < 3)    return false;
        }
        return l == s.length() && r == word.length();
    }
};