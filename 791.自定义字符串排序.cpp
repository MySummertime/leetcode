#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;


class Solution {
public:
    // customized sort
    string customSortString(string order, string s) {
        vector<int> vec(26, 0);
        for (int i = 0, len = order.length(); i < len; ++i) {
            vec[order[i] - 'a'] = i + 1;
        }
        std::sort(s.begin(), s.end(), [&](char a, char b) {
            return vec[a - 'a'] < vec[b - 'a'];
        });
        return s;
    }
};