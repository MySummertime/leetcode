#include <string>
#include <vector>
#include <algorithm>
#include <regex>

using std::string;
using std::vector;
using std::regex;
using std::regex_replace;


class Solution {
public:
    // string
    string maskPII(string s) {
        string res;
        int at = s.find("@");
        // an email
        if (at != string::npos) {
            std::transform(s.begin(), s.end(), s.begin(), ::tolower);
            return s.substr(0, 1) + "*****" + s.substr(at - 1);
        }
        // a number
        regex e("[^0-9]");
        s = regex_replace(s, e, "");
        return country[s.size() - 10] + "***-***-" + s.substr(s.size() - 4);
    }

private:
    vector<string> country = {"", "+*-", "+**-", "+***-"};
};