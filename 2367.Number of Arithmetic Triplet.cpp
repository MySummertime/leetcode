#include <vector>
#include <bitset>

using std::vector;
using std::bitset;


class Solution {
public:
    // hash map
    int arithmeticTriplets(vector<int>& nums, int diff) {
        bitset<301> vis;
        for (const int& i : nums) {
            vis[i] = 1;
        }
        int ans = 0;
        for (const int& i : nums) {
            ans += vis[i + diff] && vis[i + diff + diff];
        }
        return ans;
    }
};