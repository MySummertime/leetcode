#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;


class Solution {
public:
    // hash map & sliding window
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int ans = 0;
        int l = 0, r = 0, len = fruits.size();
        while (r < len) {
            ++mp[fruits[r]];
            if (mp.size() <= 2) {
                ans = std::max(ans, r - l + 1);
            }
            else {
                --mp[fruits[l]];
                if (mp[fruits[l]] == 0) {
                    mp.erase(fruits[l]);
                }
                ++l;
            }
            ++r;
        }
        return ans;
    }
};