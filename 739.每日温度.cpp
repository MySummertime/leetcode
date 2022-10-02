#include <vector>
#include <stack>

using std::vector;
using std::stack;


class Solution {
public:
    // monotinic stack
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int len = temperatures.size();
        vector<int> vec(len, 0);
        stack<int> stk;
        for (int i = 0, prev; i < len; ++i) {
            prev = stk.top();
            while (!stk.empty() && temperatures[i] > temperatures[prev]) {
                stk.pop();
                vec[prev] = i - prev;
            }
            stk.push(i);
        }
        return vec;
    }
};