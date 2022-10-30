#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using std::vector;
using std::string;
using std::unordered_map;


class Solution {
public:
    // sort & hash map
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string> > mp;
        for (string& s : strs) {
            string t = s;
            std::sort(t.begin(), t.end(), std::less<>());
            mp[t].push_back(s);
        }
        for (auto& n : mp) {
            ans.push_back(n.second);
        }
        return ans;
    }
};