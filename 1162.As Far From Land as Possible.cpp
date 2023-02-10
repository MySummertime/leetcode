#include <vector>
#include <queue>

using std::vector;
using std::queue;


class Solution {
public:
    // bfs
    int maxDistance(vector<vector<int>>& grid) {
        vis = grid;

        // count the number of land grids
        countLand(vis);
        if (que.empty() || que.size() == vis.size() * vis.size()) {
            return -1;
        }

        int ans = -1;
        while (!que.empty()) {
            ++ans;
            int scale = que.size();
            for (int i = 0; i < scale; ++i) {
                auto [x, y] = que.front();
                que.pop();
                for (auto d : dirs) {
                    int nx = x + d[0];
                    int ny = y + d[1];
                    if (!validOrNot(nx, ny, vis))  continue;
                    if (vis[nx][ny] != 0)   continue;
                    vis[nx][ny] = 1;
                    que.emplace(nx, ny);
                }
            }
        }
        return ans;
    }

private:
    bool validOrNot(int x, int y, const vector<vector<int>>& grid) {
        int len = grid.size();
        if (x >= 0 && x < len && y >= 0 && y < len) {
            return true;
        }
        return false;
    }

    void countLand(const vector<vector<int>>& grid) {
        for (int i = 0, len = grid.size(); i < len; ++i) {
            for (int j = 0; j < len; ++j) {
                if (grid[i][j] == 0)    continue;
                que.emplace(i, j);
            }
        }

    }

private:
    queue<std::pair<int, int>> que;
    vector<vector<int>> vis;
    static constexpr int dirs[4][2] {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};