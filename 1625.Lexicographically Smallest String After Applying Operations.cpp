#include <string>
#include <queue>
#include <unordered_set>

using std::string;
using std::queue;
using std::unordered_set;


class Solution {
public:
    // bfs
    string findLexSmallestString(string s, int a, int b) {
        queue<string> q{{s}};
        unordered_set<string> vis{{s}};
        string ans = s;
        int len = s.size();
        while (!q.empty()) {
            s = q.front();
            q.pop();
            ans = min(ans, s);
            string t1 = s;
            for (int i = 1; i < len; i += 2) {
                t1[i] = (t1[i] - '0' + a) % 10 + '0';
            }
            string t2 = s.substr(len - b) + s.substr(0, len - b);
            for (auto& t : {t1, t2}) {
                if (!vis.count(t)) {
                    vis.insert(t);
                    q.emplace(t);
                }
            }
        }
        return ans;
    }
};
