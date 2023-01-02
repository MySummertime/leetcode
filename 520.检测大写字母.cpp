#include <string>
#include <algorithm>

using std::string;


/*
class Solution {
public:
    bool detectCapitalUse(string word) {
        if (std::islower(word[0])) {
            return std::count_if(word.begin(), word.end(), [] (const char& c) {
                return std::isupper(c);
            }) == 0;
        }
        // std::isupper(word[0])
        int len = word.length();
        return std::count_if(std::next(word.begin()), word.end(), [] (const char& c) {
            return std::isupper(c);
        }) == len - 1 ||
        std::count_if(std::next(word.begin()), word.end(), [] (const char& c) {
            return std::islower(c);
        }) == len - 1;
    }
};
*/


class Solution {
public:
    // simulate
    bool detectCapitalUse(string word) {
        int len = word.length();
        if (len >= 2 && std::islower(word[0]) && std::isupper(word[1])) {
            return false;
        }
        for (int i = 2; i < len; ++i) {
            // the remaining characters' state must be the same as word[1]
            if (std::islower(word[i]) ^ std::islower(word[1])) {
                return false;
            }
        }
        return true;
    }
};