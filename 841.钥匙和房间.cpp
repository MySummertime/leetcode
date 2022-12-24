#include <vector>
#include <queue>

using std::vector;
using std::queue;


class Solution {
public:
    // bfs
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vis.resize(rooms.size(), false);
        bfs(rooms, 0);
        return checkValid();
    }

private:
    void bfs(const vector<vector<int>>& rooms, int key) {
        queue<int> que;
        que.push(key);
        vis[key] = true;
        while (!que.empty()) {
            int k = que.front();
            que.pop();
            for (const int& i : rooms[k]) {
                if (!vis[i]) {
                    que.push(i);
                    vis[i] = true;
                }
            }
        }
    }

    bool checkValid() {
        for (const bool& i : vis) {
            if (!i) return false;
        }
        return true;
    }

private:
    vector<bool> vis;
};