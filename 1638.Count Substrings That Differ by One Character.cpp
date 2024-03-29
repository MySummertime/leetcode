#include <string>

using std::string;


class Solution_1 {
public:
    // enumerate
    int countSubstrings(string s, string t) {
        int m = s.size(), n = t.size();
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int diff = 0;
                for (int k = 0; i + k < m && j + k < n; ++k) {
                    diff += (s[i + k] != t[j + k]);
                    if (diff > 1) {
                        break;
                    }
                    if (diff == 1) {
                        ++ans;
                    }
                }
            }
        }
        return ans;
    }
};


class Solution_2 {
public:
    int countSubstrings(string s, string t) {
        int m = s.size(), n = t.size();
        int mlen = std::min(m, n);
        int ans = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (s[i] == t[j])
                    continue;
                int l = 0;
                while (i - (l + 1) >= 0 && j - (l + 1) >= 0 && s[i - (l + 1)] == t[j - (l + 1)])
                    ++l;
                int r = 0;
                while (i + (r + 1) < m && j + (r + 1) < n && s[i + (r + 1)] == t[j + (r + 1)])
                    ++r;
                ans += (l + 1) * (r + 1);
            }
        return ans;
    }
};