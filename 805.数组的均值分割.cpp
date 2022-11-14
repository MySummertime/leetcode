#include <vector>
#include <map>
#include <tuple>

using std::vector;
using std::map;
using std::tuple;


class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        len = nums.size();
        sum = getTotalSum(nums);
        ans = false;
        float avg = float(sum) / len;
        for (int i = 1; i < len / 2 + 1; ++i) {
            if (sum * i % len == 0) {
                ans = ans || search(nums, avg * i, i, 0);
            }
        }
        return ans;
    }

private:
    bool search(const vector<int>& nums, float target, int i, int j) {
        if (!i) return target == 0;
        if (target < 0 || i + j > len)  return false;
        if (vis.count(tuple(target, i, j))) return vis[{target, i, j}];
        vis[{target, i, j}] = search(nums, target - nums[j], i - 1, j + 1) || search(nums, target, i, j + 1);
        return vis[{target, i, j}];
    }

    int getTotalSum(const vector<int>& nums) {
        int sum = 0;
        for (const int& i : nums) {
            sum += i;
        }
        return sum;
    }

private:
    int len;
    int sum;
    bool ans;
    map<tuple<int, int, int>, bool> vis;
};