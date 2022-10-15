#include <vector>
#include <string>

using std::vector;
using std::string;


class Solution {
public:
    // simulate
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        for (int i = 0, j = 1, len = target.size(); i < len && j <= n; ++j) {
            ans.push_back("Push");
            if (target[i] != j) ans.push_back("Pop");
            else    ++i;
        }
        return ans;
    }
};
