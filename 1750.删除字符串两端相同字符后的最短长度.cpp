#include <string>

using std::string;


class Solution {
public:
    // two pointers
    int minimumLength(string s) {
        int len = s.length();
        int l = 0, r = len - 1;
        while (l < r && s[l] == s[r]) {
            char ch = s[l];
            while (l <= r && s[l] == ch) {
                ++l;
            }
            while (l <= r && s[r] == ch) {
                --r;
            }
        }
        return r - l + 1;
    }
};