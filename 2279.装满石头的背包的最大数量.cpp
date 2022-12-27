#include <vector>
#include <algorithm>

using std::vector;


class Solution {
public:
    // sort
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        // get the gap between the volumn and the current
        for (int i = 0, len = capacity.size(); i < len; ++i) {
            capacity[i] -= rocks[i];
        }
        std::sort(capacity.begin(), capacity.end(), std::less<>());
        int ans = 0;
        for (int i = 0, len = capacity.size(); i < len; ++i) {
            if (capacity[i] > additionalRocks)  break;
            ++ans;
            additionalRocks -= capacity[i];
        }
        return ans;
    }
};