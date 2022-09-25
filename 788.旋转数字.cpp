#include <string>
#include <vector>
#include <functional>

using std::string;
using std::vector;

class Solution {
public:
    // dynamic programming
    int rotatedDigits(int n) {
        string s = std::to_string(n);
        int len = s.length();
        vector<vector<int>> dp(len, vector<int>(2, -1));

        std::function<int(int, bool, bool)> func = [&] (int i, bool has_dif, bool is_limited) -> int {
            // it's valid only if it's one of {2, 5, 6, 9}
            if (i == len) {
                return has_dif;
            }
            if (!is_limited && dp[i][has_dif] >= 0) {
                return dp[i][has_dif];
            }
            int ans = 0;
            int top = (is_limited) ? s[i] - '0' : 9;
            // traverse the number to add
            for (int d = 0; d <= top; ++d) {
                // d != {3, 4, 7}
                if (dif[d] != -1) {
                    ans += func(i + 1, has_dif || dif[d], is_limited && d == top);
                }
            }
            if (!is_limited) {
                dp[i][has_dif] = ans;
            }
            return ans;
        };

        return func(0, false, true);
    }

private:
    int dif[10] {0, 0, 1, -1, -1, 1, 1, -1, 0, 1};
};