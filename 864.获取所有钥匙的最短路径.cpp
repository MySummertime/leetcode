#include <vector>
#include <string>
#include <queue>
#include <tuple>

using std::vector;
using std::string;
using std::deque;
using std::tuple;


class Solution {
public:
    // bfs
    int shortestPathAllKeys(vector<string>& grid) {
        int n = grid.size(), m = grid[0].size(), cnt = 0;
        steps.resize(n, vector<vector<int>>(m, vector<int>((1 << K), 0x3f3f3f3f)));
        // search for the enter point by traversal
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                char ch = grid[i][j];
                // find the enter point
                if (ch == '@') {
                    deq.emplace_back(i, j, 0);
                    steps[i][j][0] = 0;
                }
                // find a key
                else if (std::islower(ch)) {
                    ++cnt;
                }
            }
        }
        return bfs(grid, cnt);
    }

private:
    int bfs(const vector<string>& grid, const int& cnt) {
        while (!deq.empty()) {
            auto [x, y, cur] = deq.front();
            deq.pop_front();
            int step = steps[x][y][cur];
            for (const int* d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size()) continue;
                char ch = grid[nx][ny];
                // find a wall
                if (ch == '#')  continue;
                // find a lock without corresponding key
                if (std::isupper(ch) && (((cur >> (ch - 'A')) & 1) == 0)) continue;
                // find a key, update the step
                int ncur = cur;
                if (std::islower(ch))   ncur |= 1 << (ch - 'a');
                // the count of keys == the current number of found keys
                // work finished, return current steps
                if (ncur == (1 << cnt) - 1) return step + 1;
                if (step + 1 >= steps[nx][ny][ncur])    continue;
                steps[nx][ny][ncur] = step + 1;
                deq.emplace_back(nx, ny, ncur);
            }
        }
        return -1;
    }

private:
    static constexpr int K = 8;
    static constexpr int SCALE = 32;
    static constexpr int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<vector<int>>> steps;
    deque<tuple<int, int, int>> deq;
};