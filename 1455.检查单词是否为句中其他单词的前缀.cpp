#include <string>
#include <sstream>

using std::string;
using std::istringstream;


class Solution {
public:
    // simulate
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream ss(sentence);
        string str;
        for (int i = 1; ss >> str; ++i) {
            if (str.find(searchWord) == 0) {
                return i;
            }
        }
        return -1;
    }
};