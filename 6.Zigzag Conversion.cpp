#include <string>
#include <vector>
#include <numeric>

using std::string;
using std::vector;


class Solution {
public:
    // simulate
    string convert(string s, int numRows) {
        if (numRows == 1)   return s;
        vector<string> vec(numRows);
        for (int i = 0, dir = 1, row = 0, len = s.length(); i < len; ++i) {
            vec[row].push_back(s[i]);
            if (row == 0)   dir = 1;
            else if (row == numRows - 1)    dir = -1;
            row += dir;
        }
        return std::accumulate(vec.begin(), vec.end(), string(""));
    }
};