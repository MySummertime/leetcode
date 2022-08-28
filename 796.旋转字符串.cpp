#include <string>

using std::string;


class Solution {
public:
    // simulate
    bool rotateString(string s, string goal) {
        int m = s.length(), n = goal.length();
        if (m != n) {
            return false;
        }
        for (int i = 0; i < n; ++i) {
            bool flag = true;
            for (int j = 0; j < n; ++j) {
                if (s[(i + j) % n] != goal[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag)   return true;
        }
        return false;
    }
};