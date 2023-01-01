#include <string>
#include <unordered_map>
#include <sstream>

using std::string;
using std::unordered_map;
using std::stringstream;


class Solution {
public:
    // hash map && stringstream
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp;
        unordered_map<string, char> rmp;
        stringstream ss(s);
        string ns;
        for (const char& ch : pattern) {
            if (!(ss >> ns))    return false;
            if (mp.find(ch) != mp.end() && mp[ch] != ns)    return false;
            if (rmp.find(ns) != rmp.end() && rmp[ns] != ch) return false;
            mp[ch] = ns;
            rmp[ns] = ch;
        }
        return (ss >> ns) ? false : true;
    }
};