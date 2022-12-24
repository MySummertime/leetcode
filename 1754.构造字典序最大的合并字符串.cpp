#include <string>

using std::string;


class Solution {
public:
    // greedy
    string largestMerge(string word1, string word2) {
        string ans;
        int l = 0, r = 0;
        while (l < word1.length() || r < word2.length()) {
            if (l < word1.length() && word1.substr(l) > word2.substr(r)) {
                ans.push_back(word1[l++]);
            }
            else {
                ans.push_back(word2[r++]);
            }
        }
        return ans;
    }
};