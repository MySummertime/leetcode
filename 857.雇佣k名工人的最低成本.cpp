#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using std::vector;
using std::priority_queue;


class Solution {
public:
    // priority queue & sort
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<vector<double>> workers;
        for (int i = 0, len = quality.size(); i < len; ++i) {
            workers.push_back({(double)(wage[i]) / quality[i], (double)quality[i]});
        }
        std::sort(workers.begin(), workers.end());
        double sum = 0;
        double ans = DBL_MAX;
        priority_queue<int> que;
        for (const vector<double>& vec : workers) {
            sum += vec[1];
            que.push(vec[1]);
            if (que.size() > k) {
                sum -= que.top();
                que.pop();
            }
            if (que.size() == k) {
                ans = std::min(ans, sum * vec[0]);
            }
        }
        return ans;
    }
};