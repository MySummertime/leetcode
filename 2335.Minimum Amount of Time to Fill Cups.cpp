#include <vector>
#include <algorithm>

using std::vector;


class Solution {
public:
    // math & greedy
    int fillCups(vector<int>& amount) {
        std::sort(amount.begin(), amount.end(), std::less<>());
        if (amount[0] + amount[1] <= amount[2]) return amount[2];
        else {
            int sum = amount[0] + amount[1] + amount[2];
            return (sum >> 1) + (sum % 2);
        }
    }
};