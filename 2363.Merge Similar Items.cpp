#include <vector>
#include <unordered_map>
#include <algorithm>

using std::vector;
using std::unordered_map;


class Solution {
public:
    // hash map && customized sort
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        unordered_map<int, int> ump;
        for (const vector<int>& i : items1) ump[i[0]] += i[1];
        for (const vector<int>& i : items2) ump[i[0]] += i[1];
        vector<vector<int>> ans;
        for (auto [k, v] : ump) ans.push_back({k, v});
        std::sort(ans.begin(), ans.end(), [&] (const vector<int> a, const vector<int> b) -> bool {
            if (a[0] == b[0])   return a[1] < b[1];
            return a[0] < b[0];
        });
        return ans;
    }
};