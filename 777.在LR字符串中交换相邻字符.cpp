#include <string>

using std::string;

class Solution {
public:
    // two pointers
    bool canTransform(string start, string end) {
        int len = start.length();
        int i = 0, j = 0;
        while (i < len && j < len) {
            while (i < len && start[i] == 'X') {
                ++i;
            }
            while (j < len && end[j] == 'X') {
                ++j;
            }
            if (i < len && j < len) {
                if (start[i] != end[j]) {
                    return false;
                }
                char ch = start[i];
                if ((ch == 'L' && i < j) || (ch == 'R' && i > j)) {
                    return false;
                }
                ++i;
                ++j;
            }
        }
        while (i < len) {
            if (start[i] != 'X') {
                return false;
            }
            ++i;
        }
        while (j < len) {
            if (end[j] != 'X') {
                return false;
            }
            ++j;
        }
        return true;
    }
};