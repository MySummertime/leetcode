#include <vector>
#include <unordered_map>
#include <queue>
#include <limits>
#include <unordered_set>

using std::vector;
using std::unordered_map;
using std::queue;
using std::unordered_set;


class Solution {
public:
    // unordered_map
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, unordered_map<int, int>> graph;
        for (const vector<int>& i : roads) {
            int u = i[0];
            int v = i[1];
            int w = i[2];
            graph[u][v] = graph[v][u] = w;
        }

        int ans = std::numeric_limits<int>::max();
        unordered_set<int> vis;
        queue<int> que;
        que.push(1);
        while (!que.empty()) {
            int node = que.front();
            que.pop();
            for (auto& [adj, score] : graph[node]) {
                if (!vis.count(adj)) {
                    que.push(adj);
                    vis.insert(adj);
                }
                ans = std::min(ans, score);
            }
        }
        return ans;
    }
};