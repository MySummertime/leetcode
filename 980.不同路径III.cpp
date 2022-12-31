#include <vector>

using std::vector;


class Solution {
public:
    // dfs && backtrack
    int uniquePathsIII(vector<vector<int>>& graph) {
        cnt = 0;
        for (int i = 0, h = graph.size(); i < h; ++i) {
            for (int j = 0, w = graph[0].size(); j < w; ++j) {
                if (graph[i][j] == 1) {
                    for (auto d : dir) {
                        int nx = i + d[0];
                        int ny = j + d[1];
                        if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                        if (graph[nx][ny] == -1)    continue;
                        dfs(graph, nx, ny);
                    }
                    return cnt;
                }
            }
        }
        return -1;
    }

private:
    void dfs(vector<vector<int>>& graph, int x, int y) {
        if (x < 0 || x >= graph.size() || y < 0 || y >= graph[0].size())    return;
        if (graph[x][y] == 1)   return;
        if (graph[x][y] == -1)  return;
        if (graph[x][y] == 2) {
            if (checkGraph(graph)) {
                ++cnt;
            }
            return;
        }
        graph[x][y] = 1;
        for (auto d : dir) {
            dfs(graph, x + d[0], y + d[1]);
        }
        // backtrack
        graph[x][y] = 0;
    }

    bool checkGraph(const vector<vector<int>>& graph) {
        for (int i = 0, h = graph.size(); i < h; ++i) {
            for (int j = 0, w = graph[0].size(); j < w; ++j) {
                if (graph[i][j] == 0)   return false;
            }
        }
        return true;
    }

private:
    int cnt = 0;
    static constexpr int dir[4][2] {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
};