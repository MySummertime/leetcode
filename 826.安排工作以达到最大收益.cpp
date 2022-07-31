#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProfitAssignment(std::vector<int>& difficulty, std::vector<int>& profit, std::vector<int>& worker) {
        int len = difficulty.size();
        std::vector<std::pair<int, int>> job;
        for (int i = 0; i < len; ++i) {
            job.push_back({difficulty[i], profit[i]});
        }
        std::sort(job.begin(),job.end());
        std::sort(worker.begin(), worker.end());
        int ans = 0;
        int i = 0;
        int earn = 0;
        for (int& person : worker) {
            while (i < len && person >= job[i].first) {
                earn = std::max(earn, job[i++].second);
            }
            ans += earn;
        }
        return ans;
    }
};