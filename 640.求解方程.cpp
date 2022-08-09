
#include <string>

using std::string;


class Solution {
public:
    // double pointers
    string solveEquation(string equation) {
        int len = equation.length();
        int flag = 1, tot = 0, coeff = 0;
        int i = 0;
        for (int j = 0; j < len; ++j) {
            if (equation[j] == '+' || equation[j] == '-') {
                if (j > i) {
                    tot += flag * std::stoi(equation.substr(i, j - i));
                }
                i = j;
            }
            else if (equation[j] == 'x') {
                if ((i == j) || equation[j - 1] == '+') {
                    coeff += flag;
                }
                else if (equation[j - 1] == '-') {
                    coeff -= flag;
                }
                else {
                    coeff += flag * std::stoi(equation.substr(i, j - i));
                }
                i = j + 1;
            }
            else if (equation[j] == '=') {
                if (j > i) {
                    tot += flag * std::stoi(equation.substr(i, j - i));
                }
                i = j + 1;
                flag *= -1;
            }
        }
        // there may be a number in the end
        if (i < len) {
            tot += flag * std::stoi(equation.substr(i));
        }
        if (coeff == 0) {
            return tot ? "No solution" : "Infinite solutions";
        }
        int ans = -tot / coeff;
        return "x=" + std::to_string(ans);
    }
};