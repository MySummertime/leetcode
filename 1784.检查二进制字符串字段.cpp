#include <string>

using std::string;

class Solution {
public:
    bool checkOnesSegment(string s) {
        return s.find('01') == string::npos;
    }
};