#include <vector>
#include <string>
#include <unordered_map>

using std::vector;
using std::string;
using std::unordered_map;


class Solution {
public:
    // customized sort
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> mp;
        int idx = 0;
        for (const char& ch : order) {
            mp[ch] = idx++;
        }

        for (int i = 0, len = words.size(); i < len - 1; ++i) {
            if (!valid(mp, words[i], words[i + 1]))
                return false;
        }
        return true;
    }

private:
    bool valid(unordered_map<char, int>& mp, const string& a, const string& b) {
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (mp[a[i]] > mp[b[j]])    return false;
            if (mp[a[i]] < mp[b[j]])    return true;
            ++i;
            ++j;
        }
        return a.length() <= b.length();
    }
};