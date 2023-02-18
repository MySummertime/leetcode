#include <vector>

using std::vector;


/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 */
class CustomFunction {
public:
    // Returns f(x, y) for any given positive integers x and y.
    // Note that f(x, y) is increasing with respect to both x and y.
    // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
    int f(int x, int y);
};


class Solution {
public:
    // two pointers
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> ans;
        for (int l = 1, r = 1000, target; l <= 1000 && r; ) {
            target = customfunction.f(l, r);
            if (target < z) ++l;
            else if (target > z)    --r;
            else    ans.push_back({l++, r--});
        }
        return ans;
    }
};