#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;


class Solution {
public:
    // simulate
    string decodeMessage(string key, string message) {
        char ch = 'a';
        unordered_map<char, char> mp;
        for (const char& c : key) {
            if (c != ' ' && mp.find(c) == mp.end()) {
                mp[c] = ch;
                ++ch;
            }
        }
        for (char& c : message) {
            if (c != ' ') {
                c = mp[c];
            }
        }
        return message;
    }
};