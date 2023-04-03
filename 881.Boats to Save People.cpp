#include <vector>
#include <algorithm>

using std::vector;


class Solution {
public:
    // sort && greedy
    int numRescueBoats(vector<int>& people, int limit) {
        std::sort(people.begin(), people.end(), std::less<>());
        int len = people.size();
        int l = 0, r = len - 1;
        int ans = 0;
        while (l <= r) {
            if (people[l] + people[r] <= limit) ++l;
            --r;
            ++ans;
        }
        return ans;
    }
};