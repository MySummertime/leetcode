#include <vector>
#include <map>
#include <algorithm>

using std::vector;
using std::map;


class Solution {
public:
    // dynamic programming + hash map
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int len = startTime.size();
        vector<vector<int>> jobs(len, vector<int>(3));
        for (int i = 0; i < len; ++i) {
            jobs[i] = {endTime[i], startTime[i], profit[i]};
        }
        // customized sort by endTime ascendingly
        std::sort(jobs.begin(), jobs.end(), [&] (auto& a, auto& b) -> bool {
            return a[0] < b[0];
        });
        map<int, int> dp {{0, 0}};
        for (auto& job : jobs) {
            int cur = std::prev(dp.upper_bound(job[1]))->second + job[2];
            if (cur > dp.rbegin()->second) {
                dp[job[0]] = cur;
            }
        }
        return dp.rbegin()->second;
    }
};