#include <string>

using std::string;


/*
class Solution {
public:
    // stack
    string removeDuplicates(string s) {
        string ans = "";
        for (char& ch : s) {
            if (ans.size() && ch == ans.back()) {
                ans.pop_back();
            }
            else {
                ans.push_back(ch);
            }
        }
        return ans;
    }
};
*/

class Solution {
public:
    // two pointers
    string removeDuplicates(string s) {
        int l = 0;
        for (int r = 0, len = s.length(); r < len; ++r, ++l) {
            s[l] = s[r];
            if (l && s[l - 1] == s[l]) {
                l -= 2;
            }
        }
        return s.substr(0, l);
    }
};