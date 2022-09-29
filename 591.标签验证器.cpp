#include <string>
#include <stack>

using std::string;
using std::stack;


class Solution {
public:
    bool isValid(string code) {
        int len = code.size();
        stack<string> stk;
        int i = 0;
        while (i < len) {
            if (code[i] == '<') {
                if (i == len - 1) {
                    return false;
                }
                if (code[i + 1] == '/') {
                    int j = code.find('>', i);
                    if (j == string::npos) {
                        return false;
                    }
                    string tagname = code.substr(i + 2, j - (i + 2));
                    if (stk.empty() || stk.top() != tagname) {
                        return false;
                    }
                    stk.pop();
                    i = j + 1;
                    if (stk.empty() && i != len) {
                        return false;
                    }
                }
                else if (code[i + 1] == '!') {
                    if (stk.empty()) {
                        return false;
                    }
                    string cdata = code.substr(i + 2, 7);
                    if (cdata != "[CDATA[") {
                        return false;
                    }
                    int j = code.find("]]>", i);
                    if (j == string::npos) {
                        return false;
                    }
                    i = j + 3;
                }
                else {
                    int j = code.find('>', i);
                    if (j == string::npos) {
                        return false;
                    }
                    string tagname = code.substr(i + 1, j - (i + 1));
                    if (tagname.size() < 1 || tagname.size() > 9) {
                        return false;
                    }
                    if (!all_of(tagname.begin(), tagname.end(), [] (unsigned char c) {return isupper(c);})) {
                        return false;
                    }
                    stk.push(move(tagname));
                    i = j + 1;
                }
            }
            else {
                if (stk.empty()) {
                    return false;
                }
                ++i;
            }
        }
        return stk.empty();
    }
};