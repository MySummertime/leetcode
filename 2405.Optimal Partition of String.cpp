#include <string>

using std::string;


class Solution {
public:
    // traversal
    int partitionString(string s) {
        int vis[26];
        memset(vis, 0, sizeof(int) * 26);
        int ans = 0;
        for (int i = 0, len = s.length(), idx = -1; i < len; ++i) {
            if (vis[s[i] - 'a'] >= idx) {
                ++ans;
                idx = i + 1;
            }
            vis[s[i] - 'a'] = i + 1;
        }
        return ans;
    }
};