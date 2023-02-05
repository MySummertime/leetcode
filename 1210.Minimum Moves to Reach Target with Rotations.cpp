#include <vector>
#include <array>
#include <queue>

using std::vector;
using std::array;
using std::queue;


class Solution {
public:
    // bfs
    int minimumMoves(vector<vector<int>>& grid) {
        int len = grid.size();

        vector<vector<array<int, 2>>> vis(len, vector<array<int, 2>>(len, {-1, -1}));
        vis[0][0][0] = 0;

        queue<std::tuple<int, int, int>> que;
        // start in horizontal manner
        que.emplace(0, 0, 0);

        while (!que.empty()) {
            auto [x, y, manner] = que.front();
            que.pop();
            if (manner == 0) {
                // go right
                if (y + 2 < len && vis[x][y + 1][0] == -1 && grid[x][y + 2] == 0) {
                    vis[x][y + 1][0] = vis[x][y][0] + 1;
                    que.emplace(x, y + 1, 0);
                }
                // go down
                if (x + 1 < len && vis[x + 1][y][0] == -1 && grid[x + 1][y] == 0 && grid[x + 1][y + 1] == 0) {
                    vis[x + 1][y][0] = vis[x][y][0] + 1;
                    que.emplace(x + 1, y, 0);
                }
                // rotate 90d clockwise
                if (x + 1 < len && y + 1 < len && vis[x][y][1] == -1 && grid[x + 1][y] == 0 && grid[x + 1][y + 1] == 0) {
                    vis[x][y][1] = vis[x][y][0] + 1;
                    que.emplace(x, y, 1);
                }
            }
            else {
                // go down
                if (x + 2 < len && vis[x + 1][y][1] == -1 && grid[x + 2][y] == 0) {
                    vis[x + 1][y][1] = vis[x][y][1] + 1;
                    que.emplace(x + 1, y, 1);
                }
                // go right
                if (y + 1 < len && vis[x][y + 1][1] == -1 && grid[x][y + 1] == 0 && grid[x + 1][y + 1] == 0) {
                    vis[x][y + 1][1] = vis[x][y][1] + 1;
                    que.emplace(x, y + 1, 1);
                }
                // rotate 90d counterclockwise
                if (x + 1 < len && y + 1 < len && vis[x][y][0] == -1 && grid[x][y + 1] == 0 && grid[x + 1][y + 1] == 0) {
                    vis[x][y][0] = vis[x][y][1] + 1;
                    que.emplace(x, y, 0);
                }
            }
        }
        // end in horizontal manner
        return vis[len - 1][len - 2][0];
    }
};
