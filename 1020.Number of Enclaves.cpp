#include <vector>
#include <queue>

using std::vector;
using std::deque;


class Solution {
public:
    // mult-sources bfs
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        deque<std::pair<int, int>> deq;
        collectSources(grid, vis, deq);
        bfs(grid, vis, deq);
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] && !vis[i][j]) {
                    ++ans;
                }
            }
        }
        return ans;
    }

private:
    void collectSources(vector<vector<int>>& grid, vector<vector<bool>>& vis, deque<std::pair<int,int>>& deq) {
        for (int i = 0, m = grid.size(); i < m; ++i) {
            for (int j = 0, n = grid[0].size(); j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    if (!grid[i][j])    continue;
                    if (vis[i][j])  continue;
                    vis[i][j] = true;
                    deq.emplace_back(i, j);
                }
            }
        }
    }

    void bfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, deque<std::pair<int, int>>& deq) {
        int m = grid.size(), n = grid[0].size();
        while (!deq.empty()) {
            auto [x, y] = deq.front();
            deq.pop_front();
            for (auto &d : dirs) {
                int nx = x + d[0];
                int ny = y + d[1];
                if (nx < 0 || nx > m - 1 || ny < 0 || ny > n - 1)   continue;
                if (!grid[nx][ny])  continue;
                if (vis[nx][ny])    continue;
                vis[nx][ny] = true;
                deq.emplace_back(nx, ny);
            }
        }
    }

private:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
};