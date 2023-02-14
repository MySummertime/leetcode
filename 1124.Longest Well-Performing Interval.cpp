#include <vector>
#include <stack>

using std::vector;
using std::stack;


class Solution {
public:
    // presum && monotonic stack
    int longestWPI(vector<int>& hours) {
        int len = hours.size();
        stack<int> stk;
        stk.push(0);
        vector<int> presum(len + 1, 0);
        for (int i = 1; i <= len; ++i) {
            presum[i] = presum[i - 1] + (hours[i - 1] > 8 ? 1 : -1);
            // collect the indexes which are probably left bounds of longest intervals
            if (presum[i] < presum[stk.top()])  stk.push(i);
        }
        int ans = 0;
        for (int i = len; i; --i) {
            while (!stk.empty() && presum[i] > presum[stk.top()]) {
                ans = std::max(ans, i - stk.top());
                stk.pop();
            }
        }
        return ans;
    }
};