#include <vector>
#include <map>

using std::vector;
using std::map;


class Solution {
public:
    // simulate
    int minimumRounds(vector<int>& tasks) {
        map<int, int> mp;
        for (const int& i : tasks) {
            ++mp[i];
        }
        int ans = 0;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            int cnt = it->second;
            if (cnt == 1)   return -1;
            if (cnt == 2)   ++ans;
            else if (cnt % 3 == 0)  ans += cnt / 3;
            else    ans += cnt / 3 + 1;
        }
        return ans;
    }
};