#include <string>
#include <vector>

using std::string;
using std::vector;


class Solution {
public:
    // binary search
    int numMatchingSubseq(string s, vector<string>& words) {
        record.resize(26);
        // record the index of each character in s
        for (int i = 0, len = s.length(); i < len; ++i) {
            record[s[i] - 'a'].emplace_back(i);
        }

        auto check = [&] (const string& word) {
            int i = -1, j;
            for (const char& c : word) {
                auto& vec = record[c - 'a'];
                j = binarySearch(vec, 0, vec.size(), i);
                if (j == vec.size())  return false;
                i = vec[j];
            }
            return true;
        };

        int ans = 0;
        // check every word in words
        for (const string& word : words) {
            if (check(word)) ++ans;
        }
        return ans;
    }

private:
    int binarySearch(const vector<int>& vec, int l, int r, const int& target) {
        int m;
        while (l < r) {
            m = l + ((r - l) >> 1);
            if (vec[m] > target) {
                r = m;
            }
            else {
                l = m + 1;
            }
        }
        return l;
    }

private:
    vector<vector<int>> record;
};