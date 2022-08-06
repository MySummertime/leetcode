#include <vector>
#include <string>

using std::vector;
using std::string;


class Solution {
public:
    // brute force
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        for (string& i : words) {
            for (string& j : words) {
                if (i != j && i.find(j) != string::npos) {
                    if (j == "#")   continue;
                    ans.emplace_back(j);
                    j = "#";
                }
            }
        }
        return ans;
    }
};
