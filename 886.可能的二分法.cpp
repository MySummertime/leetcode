#include <vector>

using std::vector;


class Solution {
public:
    // dfs
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        colour.resize(n + 1, 0);
        // group[0]: colour == 1, while group[1]: colour == 2
        group.resize(n + 1);
        for (const vector<int>& vec : dislikes) {
            group[vec[0]].emplace_back(vec[1]);
            group[vec[1]].emplace_back(vec[0]);
        }
        for (int i = 1; i <= n; ++i) {
            if (colour[i] == 0 && !dfs(i, 1)) {
                return false;
            }
        }
        return true;
    }

private:
    bool dfs(int cur_val, int cur_colour) {
        colour[cur_val] = cur_colour;
        for (auto& next_val : group[cur_val]) {
            if (colour[next_val] && colour[cur_val] == colour[next_val]) {
                return false;
            }
            if (!colour[next_val] && !dfs(next_val, 3 ^ cur_colour)) {
                return false;
            }
        }
        return true;
    }

private:
    vector<int> colour;
    vector<vector<int>> group;
};