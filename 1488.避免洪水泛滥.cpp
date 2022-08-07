
#include <vector>
#include <set>
#include <unordered_map>

using std::vector;
using std::set;
using std::unordered_map;


class Solution {
public:
    // binary search
    vector<int> avoidFlood(vector<int>& rains) {
        int len = rains.size();
        vector<int> ans(len, -1);
        unordered_map<int, int> m;  // key: value of rains, val: idx of rains
        set<int> zero;  // record the index of 0s
        for (int i = 0; i < len; ++i) {
            if (rains[i] == 0) {
                zero.insert(i);
                ans[i] = 1;
            }
            else {
                if (m.count(rains[i])) {
                    int idx = m[rains[i]];
                    // search for the first element greater than idx;
                    // that is, search for the first day that lake(idx) isn't rainy;
                    auto it = zero.upper_bound(idx);
                    if (it == zero.end()) {
                        return {};
                    }
                    ans[*it] = rains[i];
                    zero.erase(it);
                }
                m[rains[i]] = i;
            }
        }
        return ans;
    }
};