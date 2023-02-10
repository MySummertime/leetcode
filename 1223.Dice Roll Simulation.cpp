#include <vector>

using std::vector;


class Solution {
public:
    // memorized dfs
    int dieSimulator(int n, vector<int>& _rollMax) {
        rollMax = _rollMax;
        vis.resize(n, vector<vector<int>>(rollMax.size(), vector<int>(15, -1)));

        long ans = 0;
        for (int i = 0, len = rollMax.size(); i < len; ++i) {
            ans += dfs(n - 1, i, rollMax[i] - 1);
        }
        return ans % MOD;
    }

private:
    /*
        i: the steps to take
        last: the value of the last number
        left: the steps to take that is eligible for being duplicate
    */
    int dfs(int i, int last, int left) {
        if (!i) return 1;
        if (vis[i][last][left] >= 0) {
            return vis[i][last][left];
        }
        long ans = 0;
        for (int j = 0, len = rollMax.size(); j < len; ++j) {
            if (j != last)  ans += dfs(i - 1, j, rollMax[j] - 1);
            else if (left)  ans += dfs(i - 1, j, left - 1);
        }
        return vis[i][last][left] = int(ans % MOD);
    }

private:
    vector<int> rollMax;
    vector<vector<vector<int>>> vis;
    static constexpr int MOD = 1e9 + 7;
};