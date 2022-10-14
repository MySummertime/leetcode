#include <string>
#include <stack>
#include <vector>
#include <numeric>

using std::string;
using std::stack;
using std::vector;


class Solution {
public:
    // stack
    int scoreOfParentheses(string s) {
        stack<int> stk;
        for (const char& ch : s) {
            if (ch == '(')  stk.push(-1);
            else {
                int cur = 0;
                // iterate until a '(' appears at the top
                while (stk.top() != -1) {
                    cur += stk.top();
                    stk.pop();
                }
                // erase a '('
                stk.pop();
                // cur == 0: '()' at the top
                // cur > 0: '(...)' at the top
                cur = std::max(1, 2 * cur);
                stk.push(cur);
            }
        }
        int ans = 0;
        while (!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }
        return ans;
    }
};



class Solution {
public:
    // stack
    int scoreOfParentheses(string s) {
        vector<int> vec;
        for (const char& ch : s) {
            if (ch == '(')  vec.push_back(-1);
            else {
                int cur = 0;
                while (vec.back() != -1) {
                    cur += vec.back();
                    vec.pop_back();
                }
                // erase the '(' at the top
                vec.pop_back();
                // cur == 0: '()' at the top
                // cur > 0: '(...)' at the top
                cur = std::max(1, 2 * cur);
                vec.push_back(cur);
            }
        }
        return std::accumulate(vec.begin(), vec.end(), 0);
    }
};