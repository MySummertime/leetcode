#include <vector>

using std::vector;


class Solution {
public:
    // simulate
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int steps = -1;
        int max_margin = 0;
        int ground = 0, board = 0;
        for (int i = 0; i < customers.size() || ground > 0; ++i) {
            if (i < customers.size())   ground += customers[i];
            if (ground >= 4) {
                ground -= 4;
                board += 4;
            }
            else {
                board += ground;
                ground = 0;
            }
            // update the maximum revenue
            if (board * boardingCost - runningCost * (i + 1) > max_margin) {
                steps = i + 1;
                max_margin = board * boardingCost - runningCost * (i + 1);
            }
        }
        return steps;
    }
};