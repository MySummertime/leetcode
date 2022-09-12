#include <string>
#include <stack>

using std::string;
using std::stack;

class Solution {
public:
    // stack simulation
    string reverseParentheses(string s) {
        stack<string> stk;
        string ans;
        for (const char& c : s) {
            if (c == '(') {
                stk.push(ans);
                ans.clear();
            }
            else if (c == ')') {
                std::reverse(ans.begin(), ans.end());
                ans = stk.top() + ans;
                stk.pop();
            }
            else {
                ans.push_back(c);
            }
        }
        return ans;
    }
};