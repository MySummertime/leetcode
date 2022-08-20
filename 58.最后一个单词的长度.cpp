#include <string>

using std::string;


class Solution {
public:
    // double pointers
    int lengthOfLastWord(string s) {
        int len = s.length();
        int r = len - 1;
        while (r >= 0 && s[r] == ' ') {
            --r;
        }
        if (r < 0) {
            return 0;
        }
        int l = r;
        while (l >= 0 && s[l] != ' ') {
            --l;
        }
        return r - l;
    }
};