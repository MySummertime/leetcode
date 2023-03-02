#include <vector>
#include <string>

using std::vector;
using std::string;


class Solution {
public:
    // two pointers
    int compress(vector<char>& chars) {
        int len = chars.size();
        if (len == 1)  return 1;
        int i = 0, j = 0;
        while (i < len) {
            int cnt = 1;
            while (i < len - 1 && chars[i] == chars[i + 1]) {
                ++cnt;
                ++i;
            }
            chars[j++] = chars[i++];
            if (cnt > 1) {
                string str = std::to_string(cnt);
                for (const char& ch : str) {
                    chars[j++] = ch;
                }
            }
        }
        return j;
    }
};