#include <vector>
#include <stack>

using std::vector;
using std::stack;

class Solution {
public:
    // monotinic stack
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        vector<int> left(len), right(len);
        stack<int> stk;
        for (int i = 0; i < len; ++i) {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) {
                stk.pop();
            }
            left[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }
        stk = stack<int>();
        for (int i = len - 1; i >= 0; --i) {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) {
                stk.pop();
            }
            right[i] = stk.empty() ? len : stk.top();
            stk.push(i);
        }
        int ans = 0;
        for (int i = 0; i < len; ++i) {
            ans = std::max(ans, (right[i] - left[i] - 1) * heights[i]);
        }
        return ans;
    }
};