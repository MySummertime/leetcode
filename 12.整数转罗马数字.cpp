#include <string>
#include <vector>

using std::string;
using std::vector;


class Solution {
public:
    // simulate
    string intToRoman(int num) {
        string ans;
        for (int i = 0; i < SCALE && num; ++i) {
            int cur_val = val[i];
            string cur_str = str[i];
            while (num >= cur_val) {
                ans.append(cur_str);
                num -= cur_val;
            }
        }
        return ans;
    }

private:
    static constexpr int SCALE = 13;
    string str[SCALE] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int val[SCALE] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
};