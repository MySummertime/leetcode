#include <vector>
#include <stack>

using std::vector;
using std::stack;


class Solution {
public:
    // monotinic stack
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        if (len == 1)   return heights[0];
        int ans = 0;
        stack<int> stk;
        for (int i = 0; i < len; ++i) {
            while (!stk.empty() && heights[i] < heights[stk.top()]) {
                int h = heights[stk.top()];
                stk.pop();
                int w = i;
                if (!stk.empty()) {
                    w = i - stk.top() - 1;
                }
                ans = std::max(ans, h * w);
            }
            stk.push(i);
        }
        while (!stk.empty()) {
            int h = heights[stk.top()];
            stk.pop();
            int w = len;
            if (!stk.empty()) {
                w = len - stk.top() - 1;
            }
            ans = std::max(ans, h * w);
        }
        return ans;
    }
};


/*
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
*/