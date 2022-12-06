#include <string>
#include <unordered_set>

using std::string;
using std::unordered_set;


class Solution {
public:
    // hash set & two pointers
    int numDifferentIntegers(string word) {
        unordered_set<string> st;
        int l = 0, r = 0, len = word.length();
        while (true) {
            // get the left bound of digits
            while (l < len && !isdigit(word[l])) {
                ++l;
            }
            if (l == len) {
                break;
            }
            r = l;
            // get the right bound of digits
            while (r < len && isdigit(word[r])) {
                ++r;
            }
            // concatenate leading zeros
            while (r - l > 1 && word[l] == '0') {
                ++l;
            }
            st.insert(word.substr(l, r - l));
            l = r;
        }
        return st.size();
    }
};