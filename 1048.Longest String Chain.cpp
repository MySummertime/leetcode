#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using std::vector;
using std::string;
using std::unordered_map;


class Solution {
public:
    // unordered_map & customized sort
    int longestStrChain(vector<string>& words) {
        // sort the vector in descending order by length
        std::sort(words.begin(), words.end(), [&] (const string &a, const string &b) -> bool {
            return a.length() < b.length();
        });
        // key: word; value: count
        unordered_map<string, int> ump;
        int ans = 0;
        for (string &word : words) {
            ump[word] = 1;
            for (int i = 0, len = word.length(); i < len; ++i) {
                string prev = word.substr(0, i) + word.substr(i + 1);
                if (ump.find(prev) != ump.end()) {
                    ump[word] = std::max(ump[word], ump[prev] + 1);
                }
            }
            ans = std::max(ans, ump[word]);
        }
        return ans;
    }
};