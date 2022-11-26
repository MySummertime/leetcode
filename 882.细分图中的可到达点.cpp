#include <vector>
#include <queue>

using std::vector;
using std::priority_queue;


class Solution {
public:
    // dijkstra
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<std::pair<int, int>>> g(n);
        // initialize the graph
        for (auto& e : edges) {
            int u = e[0], v = e[1], cnt = e[2];
            g[u].emplace_back(v, cnt + 1);
            g[v].emplace_back(u, cnt + 1);
        }
        // find the shortest path starting from index 0
        vector<int> dist = dijkstra(g, 0);
        int ans = 0;
        for (int& d : dist) {
            if (d <= maxMoves)  ++ans;
        }
        for (auto& e : edges) {
            int u = e[0], v = e[1], cnt = e[2];
            int a = std::max(maxMoves - dist[u], 0);
            int b = std::max(maxMoves - dist[v], 0);
            ans += std::min(a + b, cnt);
        }
        return ans;
    }

private:
    vector<int> dijkstra(const vector<vector<std::pair<int, int>>>& g, int start) {
        vector<int> dist(g.size(), INT32_MAX);
        dist[start] = 0;
        priority_queue<std::pair<int, int>, vector<std::pair<int, int>>, std::greater<>> pq;
        // pair<length of edge, index of point>
        pq.emplace(0, start);
        while (!pq.empty()) {
            auto [d, x] = pq.top();
            pq.pop();
            // shorter edges only
            if (d > dist[x])    continue;
            for (auto [y, wt] : g[x]) {
                int nd = dist[x] + wt;
                if (nd < dist[y]) {
                    dist[y] = nd;
                    pq.emplace(nd, y);
                }
            }
        }
        return dist;
    }
};