#include <vector>
#include <string>

using std::vector;
using std::string;


class Solution {
public:
    // two pointers
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        int len = queries.size(), plen = pattern.length();
        vector<bool> ans(len, true);
        for (int i = 0, r; i < len; ++i) {
            r = 0;
            for (int l = 0; l < queries[i].length(); ++l) {
                if (r < plen && queries[i][l] == pattern[r]) {
                    ++r;
                }
                else if (std::isupper(queries[i][l])) {
                    ans[i] = false;
                    break;
                }
            }
            if (r < plen) ans[i] = false;
        }
        return ans;
    }
};