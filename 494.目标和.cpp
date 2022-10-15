#include <vector>
#include <string>
#include <numeric>
#include <unordered_map>

using std::vector;
using std::string;
using std::unordered_map;


class Solution {
public:
    // dynamic programming
    // (sum − neg) − neg = sum − 2 * neg = target
    // neg = (sum − target) / 2
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        int dif = sum - target;
        if (dif < 0 || dif & 1) return 0;
        int len = nums.size();
        int neg = dif >> 1;
        vector<vector<int>> dp(len + 1, vector<int>(neg + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= len; ++i) {
            for (int j = 0; j <= neg; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (j >= nums[i - 1]) {
                    dp[i][j] += dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp[len][neg];
    }
};


/*
class Solution {
public:
    // dynamic programming
    int findTargetSumWays(vector<int>& nums, int target) {
        int len = nums.size();
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        int dif = sum - target;
        if (dif < 0)    return 0;
        vector<vector<int>> dp(len + 1, vector<int>(2 * sum + 1));
        // the edge between negative sum and positive sum
        dp[0][sum] = 1;
        for (int i = 1, cur; i <= len; ++i) {
            cur = nums[i - 1];
            for (int j = -sum; j <= sum; ++j) {
                if ((j - cur) + sum >= 0) {
                    dp[i][j + sum] += dp[i - 1][(j - cur) + sum];
                }
                if ((j + cur) + sum <= 2 * sum) {
                    dp[i][j + sum] += dp[i - 1][(j + cur) + sum];
                }
            }
        }
        return dp[len][target + sum];
    }
};
*/

/*
class Solution {
public:
    // memorized dfs
    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(nums, target, 0, 0);
    }

private:
    int dfs(const vector<int>& vec, const int& target, int idx, int sum) {
        string key = std::to_string(idx);
        key.append("_" + std::to_string(sum));
        auto it = vis.find(key);
        if (it != vis.end()) {
            return (*it).second;
        }
        if (idx == vec.size()) {
            vis.insert({key, target == sum ? 1 : 0});
            return vis[key];
        }
        int left = dfs(vec, target, idx + 1, sum + vec[idx]);
        int right = dfs(vec, target, idx + 1, sum - vec[idx]);
        vis.insert({key, left + right});
        return vis[key];
    }

private:
    unordered_map<string, int> vis;
};
*/

/*
class Solution {
public:
    // preorder dfs
    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(nums, target, 0, 0);
    }

private:
    int dfs(const vector<int>& vec, const int& target, int idx, int sum) {
        if (idx == vec.size()) {
            return target == sum ? 1 : 0;
        }
        int left = dfs(vec, target, idx + 1, sum + vec[idx]);
        int right = dfs(vec, target, idx + 1, sum - vec[idx]);
        return left + right;
    }
};
*/

