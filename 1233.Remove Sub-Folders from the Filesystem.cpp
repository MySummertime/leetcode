#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;


class Solution {
public:
    // sort
    vector<string> removeSubfolders(vector<string>& folder) {
        std::sort(folder.begin(), folder.end(), std::less<>());
        vector<string> ans;
        for (const string& s : folder) {
            if (ans.empty()
                || ans.back().compare(0, ans.back().length(), s, 0, ans.back().length()) != 0
                || s[ans.back().length()] != '/') {
                ans.push_back(s);
            }
        }
        return ans;
    }
};