#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;


class Solution {
public:
    // dfs recursion
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        adj_list.resize(n);
        for (const vector<int> &e : edges) {
            adj_list[e[0]].push_back(e[1]);
            adj_list[e[1]].push_back(e[0]);
        }
        return dfs(hasApple, 0, 0, -1) * 2;
    }

private:
    int dfs(const vector<bool>& hasApple, int vertice, int d, int prev) {
        int ans = 0, temp;
        for (int &i : adj_list[vertice]) {
            // make sure the edge is not a circuit
            if (i != prev) {
                temp = dfs(hasApple, i, d + 1, vertice);
                if (temp)   ans += temp - d;
            }
        }
        return ans || hasApple[vertice] ? ans + d : 0;
    }

private:
    vector<vector<int>> adj_list;
};