#include <string>

using std::string;


class Solution {
public:
    // traversal
    int minimumMoves(string s) {
        int ans = 0;
        for (int i = 0, len = s.length(); i < len; ++i) {
            if (s[i] == 'X') {
                ++ans;
                i += 2;
            }
        }
        return ans;
    }
};