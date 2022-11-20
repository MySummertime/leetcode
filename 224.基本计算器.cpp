#include <string>
#include <stack>

using std::string;
using std::stack;


class Solution {
public:
    // simulate
    int calculate(string s) {
        stack<int> nums, ops;
        long num = 0;
        int rst = 0, sign = 1;
        for (const char& ch : s) {
            if (std::isdigit(ch)) {
                num = 10 * num + ch - '0';
            }
            else {
                rst += sign * num;
                num = 0;
                if (ch == '+')  sign = 1;
                if (ch == '-')  sign = -1;
                if (ch == '(') {
                    nums.push(rst);
                    ops.push(sign);
                    rst = 0;
                    sign = 1;
                }
                if (ch == ')' && !ops.empty()) {
                    rst = ops.top() * rst + nums.top();
                    ops.pop();
                    nums.pop();
                }
            }
        }
        rst += sign * num;
        return rst;
    }
};