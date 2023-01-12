#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;


class Solution {
public:
    // dfs recursion && backtrack
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        adj_list.resize(n);
        for (const vector<int> &e : edges) {
            adj_list[e[0]].push_back(e[1]);
            adj_list[e[1]].push_back(e[0]);
        }
        return 2 * dfs(hasApple, 0, 0, -1);
    }

private:
    int dfs(const vector<bool>& hasApple, int idx, int dis, int prev) {
        int ans = 0;
        // traverse the sub-tree of vertice at 'idx'
        for (const int& i : adj_list[idx]) {
            // in case that we trace back to the vertice at 'idx'(cycle)
            if (i != prev) {
                int cnt = dfs(hasApple, i, dis + 1, idx);
                // if we found some apples in the sub-tree
                // we add the newly accumulated distance into the answer before backtracking the distance
                if (cnt)    ans += cnt - dis;
            }
        }
        // if some apples were found in this round,
        // return the formerly accumulated distance + ans.
        // if no apple was found in this round,
        // simply return the formerly accumulated distance.
        if (ans || hasApple[idx]) {
            return ans + dis;
        }
        return 0;
    }

private:
    vector<vector<int>> adj_list;
};