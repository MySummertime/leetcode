#include <vector>
#include <queue>
#include <tuple>

using std::vector;
using std::queue;
using std::tuple;


class Solution {
public:
    // bfs
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        queue<tuple<int, int, int>> que;
        que.emplace(entrance[0], entrance[1], 0);
        // outline the entrance as wall
        maze[entrance[0]][entrance[1]] = '+';
        while (!que.empty()) {
            auto [cx, cy, d] = que.front();
            que.pop();
            for (auto& dir : dirs) {
                int nx = cx + dir[0];
                int ny = cy + dir[1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                // find an empty cell
                if (maze[nx][ny]== '.') {
                    if (nx == 0 || nx == m - 1 || ny == 0 || ny == n - 1) {
                        return d + 1;
                    }
                    // outline the cell visited
                    maze[nx][ny] = '+';
                    que.emplace(nx, ny, d + 1);
                }
            }
        }
        return -1;
    }

private:
    const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};