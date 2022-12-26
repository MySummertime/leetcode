#include <string>

using std::string;


class Solution {
public:
    int countHomogenous(string s) {
        int ans = 0;
        int l = 0, r = 0;
        while (r < s.length()) {
            if (s[l] != s[r]) {
                l = r;
            }
            else {
                ans += (r - l + 1) % MOD;
            }
        }
        return ans;
    }

private:
    static constexpr int MOD = 1e9 + 7;
};