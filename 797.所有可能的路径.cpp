#include <vector>

using std::vector;


class Solution {
public:
    // dfs && backtrack
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        len = graph.size();
        ans.clear();
        path.clear();
        path.push_back(0);
        dfs(graph, 0);
        return ans;
    }

private:
    void dfs(const vector<vector<int>>& graph, int node) {
        if (node == len - 1) {
            ans.push_back(path);
            return;
        }
        for (const int& i : graph[node]) {
            path.push_back(i);
            dfs(graph, i);
            // backtrack
            path.pop_back();
        }
    }

private:
    int len;
    vector<int> path;
    vector<vector<int>> ans;
};