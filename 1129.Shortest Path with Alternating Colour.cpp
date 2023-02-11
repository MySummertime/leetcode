#include <vector>
#include <queue>

using std::vector;
using std::queue;


class Solution {
public:
    // bfs
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> red_grid(n);
        vector<vector<int>> blue_grid(n);
        for (const vector<int>& vec : redEdges) {
            red_grid[vec[0]].push_back(vec[1]);
        }
        for (const vector<int>& vec : blueEdges) {
            blue_grid[vec[0]].push_back(vec[1]);
        }

        /*
        1d: colour of current node
        2d: colour of next node
        3d: [0] == 1: blue visited, [0] == 0: blue unvisited;
            [1] == 1: red visited, [1] == 0: red unvisited;
        */
        int vis[128][128][2];
        memset(vis, 0, sizeof(vis));

        vector<int> ans(n, INT32_MAX);

        // first: current node
        // second: colour of current node
        queue<std::pair<int, int>> que;
        que.emplace(0, 0);  // blue0
        que.emplace(0, 1);  // red1

        int cur_len = 0;
        while (!que.empty()) {
            ++cur_len;
            for (int i = 0, len = que.size(); i < len; ++i) {
                auto [node, colour] = que.front();
                que.pop();

                // current node is red, need a blue node0
                if (colour) {
                    for (auto next : blue_grid[node]) {
                        if (!vis[node][next][0]) {
                            ans[next] = std::min(ans[next], cur_len);
                            vis[node][next][0] = 1;
                            que.emplace(next, 0);
                        }
                    }
                }
                // current node is blue, need a red node1
                else {
                    for (auto next : red_grid[node]) {
                        if (!vis[node][next][1]) {
                            ans[next] = std::min(ans[next], cur_len);
                            vis[node][next][1] = 1;
                            que.emplace(next, 1);
                        }
                    }
                }
            }
        }

        ans[0] = 0;
        for (int i = 0; i < n; ++i) {
            ans[i] = ans[i] == INT32_MAX ? -1 : ans[i];
        }
        return ans;
    }
};