#include <vector>
#include <queue>

using std::vector;
using std::queue;


/*
class Solution {
public:
    // bfs
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // construct a graph from edges
        vector<vector<int>> graph(n);
        for (const vector<int>& e : edges) {
            graph[e[0]].emplace_back(e[1]);
            graph[e[1]].emplace_back(e[0]);
        }
        // record whether a vertex was visited
        vector<bool> vis(n, false);
        // use a queue to record visited vertices
        queue<int> que;
        que.push(source);
        vis[source] = true;
        while (!que.empty()) {
            int pre = que.front();
            que.pop();
            if (pre == destination) break;
            for (auto &next : graph[pre]) {
                if (!vis[next]) {
                    que.push(next);
                    vis[next] = true;
                }
            }
        }
        return vis[destination];
    }
};
*/

class Solution {
public:
    // dfs
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // construct a graph by edges
        vector<vector<int>> graph(n);
        for (const vector<int>& e : edges) {
            graph[e[0]].emplace_back(e[1]);
            graph[e[1]].emplace_back(e[0]);
        }
        vector<bool> vis(n, false);
        return dfs(vis, graph, source, destination);
    }

private:
    bool dfs(vector<bool>& vis, const vector<vector<int>>& graph, const int& source, const int& destination) {
        if (source == destination)  return true;
        vis[source] = true;
        for (const int& next : graph[source]) {
            if (!vis[next] && dfs(vis, graph, next, destination)) {
                return true;
            }
        }
        return false;
    }
};