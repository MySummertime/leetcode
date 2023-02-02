#include <vector>
#include <unordered_map>
#include <queue>

using std::vector;
using std::unordered_map;
using std::queue;


class Solution {
public:
    // bfs
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        unordered_map<int, vector<int>> rmp;
        unordered_map<int, vector<int>> bmp;
        for (const vector<int>& vec : redEdges) {
            rmp[vec[0]].push_back(vec[1]);
        }
        for (const vector<int>& vec : blueEdges) {
            bmp[vec[0]].push_back(vec[1]);
        }
        // 1d: current node
        // 2d: next node
        // 3d: visited or not
        int vis[100][100][2];
        memset(vis, 0, sizeof(vis));

        vector<int> ans(n, INT32_MAX);

        // first: current node
        // second: lastest edge colour
        queue<std::pair<int, int>> que;
        que.emplace(0, 0);  // blue
        que.emplace(0, 1);  // red

        int clen = 0;
        while (!que.empty()) {
            ++clen;
            for (int i = 0, len = que.size(); i < len; ++i) {
                int cnode = que.front().first;
                int ccolour = que.front().second;
                que.pop();
                // need a red edge
                if (!ccolour) {
                    for (auto nnode : rmp[cnode]) {
                        if (!vis[cnode][nnode][0]) {
                            ans[nnode] = std::min(ans[nnode], clen);
                            que.emplace(nnode, 1);
                            vis[cnode][nnode][0] = 1;
                        }
                    }
                }
                // need a blue edge
                else {
                    for (auto nnode : bmp[cnode]) {
                        if (!vis[cnode][nnode][1]) {
                            ans[nnode] = std::min(ans[nnode], clen);
                            que.emplace(nnode, 0);
                            vis[cnode][nnode][1] = 1;
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