#include <vector>
#include <string>
#include <unordered_set>

using std::vector;
using std::string;
using std::unordered_set;


class Solution_1 {
public:
    long long distinctNames(vector<string>& ideas) {
        long long ans = 0;
        vector<unordered_set<string>> vec(26);
        // generate a map of distinct ideas
        for (const string& s : ideas) {
            vec[s[0] - 'a'].insert(s.substr(1));
        }
        for (int i = 0, len = vec.size(); i < len - 1; ++i) {
            for (int j = i + 1; j < len; ++j) {
                // generate a set of all the union strings
                unordered_set<string> ust;
                ust.insert(vec[i].begin(), vec[i].end());
                ust.insert(vec[j].begin(), vec[j].end());
                ans += (ust.size() - vec[i].size()) * (ust.size() - vec[j].size());
            }
        }
        return ans * 2;
    }
};


class Solution_2 {
public:
    long long distinctNames(vector<string>& ideas) {
        long long ans = 0;
        vector<unordered_set<string>> vec(26);
        // generate a map of distinct ideas
        for (const string& s : ideas) {
            vec[s[0] - 'a'].insert(s.substr(1));
        }
        for (int i = 0, len = vec.size(); i < len - 1; ++i) {
            for (int j = i + 1; j < len; ++j) {
                // get the number of union strings
                int cnt = 0;
                for (const string& s : vec[i]) {
                    if (vec[j].find(s) == vec[j].end()) {
                        ++cnt;
                    }
                }
                ans += (vec[i].size() - cnt) * (vec[j].size() - cnt);
            }
        }
        return ans * 2;
    }
};