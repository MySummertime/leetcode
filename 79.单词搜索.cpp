#include <vector>
#include <string>

using std::vector;
using std::string;


class Solution {
public:
    // backtrack
    bool exist(vector<vector<char>>& _board, string _word) {
        h = _board.size();
        if (!h) return false;
        w = _board[0].size();
        if (!w) return false;
        vis.resize(h, vector<int>(w, false));
        word = _word;
        len = word.length();
        board = _board;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (dfs(i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(int x, int y, int idx) {
        if (idx == len - 1) {
            return board[x][y] == word[idx];
        }
        if (board[x][y] == word[idx]) {
            vis[x][y] = true;
            for (auto& dir : dirs) {
                int nx = x + dir[0];
                int ny = y + dir[1];
                if (checkCoorValide(nx, ny)) {
                    if (!vis[nx][ny]) {
                        if (dfs(nx, ny, idx + 1)) {
                            return true;
                        }
                    }
                }
            }
            // backtrack
            vis[x][y] = false;
        }
        return false;
    }

    bool checkCoorValide(int x, int y) {
        return 0 <= x && x < h && 0 <= y && y < w;
    }

private:
    int h, w;
    vector<vector<int>> vis;
    vector<vector<char>> board;
    string word;
    int len;
    static constexpr int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};