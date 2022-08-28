#include <string>

using std::string;


class Solution {
public:
    // simulate
    bool checkRecord(string s) {
        int len = s.length();
        for (int i = 0, a = 0, l = 0; i < len; ) {
            if (s[i] == 'A') {
                ++a;
                if (a >= 2) return false;
            }
            else if (s[i] == 'L') {
                int j = i;
                while (s[j] == 'L') ++j;
                int len = j - i;
                if (len >= 3)   return false;
                i = j;
                continue;
            }
            ++i;
        }
        return true;
    }
};