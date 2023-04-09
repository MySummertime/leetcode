#include <string>
#include <vector>

using std::string;
using std::vector;


class Solution {
public:
    // hash map
    bool checkDistances(string s, vector<int>& distance) {
        int vis[26] {};
        for (int i = 0, len = s.length(), ch; i < len; ++i) {
            ch = s[i] - 'a';
            if (vis[ch] && i - vis[ch] != distance[ch]) {
                return false;
            }
            vis[ch] = i + 1;
        }
        return true;
    }
};