#include <vector>
#include <string>

using std::vector;
using std::string;


class Solution {
public:
    // simulate
    int minDeletionSize(vector<string>& strs) {
        int ans = 0;
        for (int j = 0, w = strs[0].length(); j < w; ++j) {
            for (int i = 0, h = strs.size(); i < h - 1; ++i) {
                if (strs[i + 1][j] < strs[i][j]) {
                    ++ans;
                    break;
                }
            }
        }
        return ans;
    }
};