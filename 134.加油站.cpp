#include <vector>

using std::vector;


class Solution {
public:
    // dfa
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for (int start = 0, len = gas.size(); start < len; ) {
            if (gas[start] < cost[start]) {
                ++start;
            }
            else {
                // the remaining gas after reaching index start
                int cur = gas[start] - cost[start];
                // enter the loop starting from index start
                int idx = start + 1;
                while (idx % len != start) {
                    // gas used up, can't finish the whole circle
                    if ((cur += gas[idx % len] - cost[idx % len]) < 0) {
                        break;
                    }
                    // gas is sufficient
                    else {
                        ++idx;
                    }
                }
                // finish the whole circle
                if (idx % len == start) return start;
                // can't finish the whole circle, restart from index idx
                else    start = idx;
            }
        }
        return -1;
    }
};