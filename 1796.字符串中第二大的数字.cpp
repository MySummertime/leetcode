#include <string>

using std::string;


class Solution {
public:
    // traversal
    int secondHighest(string s) {
        int a = -1, b = -1, cur;
        for (const char& c : s) {
            if (std::isdigit(c)) {
                cur = c - '0';
                // find a number larger than a, which is larger than b
                if (cur > a) {
                    b = a;
                    a = cur;
                }
                else if (a > cur && cur > b) {
                    b = cur;
                }
            }
        }
        return b;
    }
};