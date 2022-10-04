#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    // greedy
    int minCost(string colors, vector<int>& neededTime) {
        int i = 0, len = colors.length();
        int ans = 0;
        while (i < len) {
            char ch = colors[i];
            int max_val = 0;
            int sum = 0;
            while (i < len && colors[i] == ch) {
                max_val = std::max(max_val, neededTime[i]);
                sum += neededTime[i];
                ++i;
            }
            ans += sum - max_val;
        }
        return ans;
    }
};