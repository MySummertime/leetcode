
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;


class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int len = groupSizes.size();
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < len; ++i) {
            m[groupSizes[i]].emplace_back(i);
        }
        vector<vector<int>> ans;
        for (auto& [s, p] : m) {
            int scale = p.size() / s;
            for (int i = 0; i < scale; ++i) {
                vector<int> tmp;
                int l = i * s;
                for (int j = 0; j < s; ++j) {
                    tmp.emplace_back(p[l + j]);
                }
                ans.emplace_back(tmp);
            }
        }
        return ans;
    }
};