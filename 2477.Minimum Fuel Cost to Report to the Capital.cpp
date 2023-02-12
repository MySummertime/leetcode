#include <vector>

using std::vector;


#define LL long long

class Solution {
public:
    // dfs
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        vis.resize(roads.size() + 1, false);
        graph.resize(roads.size() + 1);

        for (const vector<int>& r : roads) {
            graph[r[0]].push_back(r[1]);
            graph[r[1]].push_back(r[0]);
        }

        LL ans = 0;
        dfs(seats, 0, ans);
        return ans;
    }

private:
    LL dfs(const int& seats, int u, LL& ans) {
        if (vis[u]) return 0;
        vis[u] = 1;
        LL city_cnt = 1;
        for (const int& v : graph[u]) {
            city_cnt += dfs(seats, v, ans);
        }
        int fuel = city_cnt / seats;
        if (city_cnt % seats)   ++fuel;
        if (u)  ans += fuel;
        return city_cnt;
    }

private:
    vector<vector<int>> graph;
    vector<bool> vis;
};