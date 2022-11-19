#include <vector>
#include <algorithm>

using std::vector;


class Solution {
public:
    // geometry
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        std::sort(trees.begin(), trees.end(), [&] (vector<int>& a, vector<int>& b) -> bool {
            return a[0] != b[0] ? a[0] > b[0] : a[1] > b[1];
        });
        int len = trees.size(), tp = 0;
        vector<int> stk(len + 10);
        vector<bool> vis(len + 10);
        stk[++tp] = 0;
        for (int i = 1; i < len; ++i) {
            vector<int> c = trees[i];
            while (tp >= 2) {
                vector<int> a = trees[stk[tp - 1]], b = trees[stk[tp]];
                if (area(a, b, c) > 0)  vis[stk[tp--]] = false;
                else break;
            }
            stk[++tp] = i;
            vis[i] = true;
        }
        int size = tp;
        for (int i = len - 1; i >= 0; --i) {
            if (vis[i]) continue;
            vector<int> c = trees[i];
            while (tp > size) {
                vector<int> a = trees[stk[tp - 1]], b = trees[stk[tp]];
                if (area(a, b, c) > 0)  --tp;
                else break;
            }
            stk[++tp] = i;
        }
        vector<vector<int>> ans(tp - 1, vector<int>(2));
        for (int i = 1; i < tp; ++i) ans[i - 1] = trees[stk[i]];
        return ans;
    }

private:
    // vector subtraction
    vector<int> subtraction(vector<int>& a, vector<int>& b) {
        return {a[0] - b[0], a[1] - b[1]};
    }

    // vector cross product
    double cross(vector<int> a, vector<int> b) {
        return a[0] * b[1] - b[0] * a[1];
    }

    // area while vector moves
    double area(vector<int>& a, vector<int>& b, vector<int>& c) {
        return cross(subtraction(b, a), subtraction(c, a));
    }
};