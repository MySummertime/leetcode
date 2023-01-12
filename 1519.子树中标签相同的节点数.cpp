#include <vector>
#include <string>

using std::vector;
using std::string;


class Solution {
public:
    // dfs recursion
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        adj_lst.resize(n);
        vis.resize(n, false);
        vector<int> ans(n, 0);
        // produce an adjacency table of vertices index
        for (const vector<int>& e : edges) {
            adj_lst[e[0]].push_back(e[1]);
            adj_lst[e[1]].push_back(e[0]);
        }
        dfs(0, ans, labels);
        return ans;
    }

private:
    vector<int> dfs(int idx, vector<int>& ans, const string& labels) {
        // mark the index of vertice we checked
        vis[idx] = true;
        // count the number of each char of the subteee of vertice which is in 'idx'
        vector<int> cnt(26, 0);
        ++cnt[labels[idx] - 'a'];
        // recursion by traversing the adjacency table
        for (const int& i : adj_lst[idx]) {
            if (vis[i]) continue;
            vector<int> tmp = dfs(i, ans, labels);
            if (!tmp.empty()) {
                for (int j = 0; j < tmp.size(); ++j) {
                    cnt[j] += tmp[j];
                }
            }
        }
        // update the answer vector
        ans[idx] = cnt[labels[idx] - 'a'];
        return cnt;
    }

private:
    vector<vector<int>> adj_lst;
    vector<bool> vis;
};