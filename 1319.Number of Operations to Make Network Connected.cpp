#include <vector>

using std::vector;


class Solution {
public:
    // dfs
    int makeConnected(int n, vector<vector<int>>& connections) {
        int len = connections.size();
        if (len < n - 1)    return -1;
        graph.resize(n);
        for (const vector<int>& i : connections) {
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        vis.resize(n, false);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                dfs(i);
                ++ans;
            }
        }
        return ans - 1;
    }

private:
    void dfs(int node) {
        vis[node] = true;
        for (const int& i : graph[node]) {
            if (!vis[i]) {
                dfs(i);
            }
        }
    }

private:
    vector<vector<int>> graph;
    vector<bool> vis;
};