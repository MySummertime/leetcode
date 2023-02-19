#include <vector>
#include <array>
#include <queue>

using std::vector;
using std::array;
using std::priority_queue;


class Solution {
public:
    // priority queue
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        double ans = 0;
        priority_queue<std::pair<double, array<int, 2>>> pq;
        for (const vector<int>& c : classes) {
            double profit = double(c[0]) / c[1];
            ans += profit;
            pq.push({getSurplus(c[0], c[1]), {c[0], c[1]}});
        }
        while (extraStudents--) {
            auto [profit, c] = pq.top();
            pq.pop();
            ans += profit;
            pq.push({getSurplus(c[0] + 1, c[1] + 1), {c[0] + 1, c[1] + 1}});
        }
        return ans / classes.size();
    }

private:
    double getSurplus(double surplus, double base) {
        return (surplus + 1) / (base + 1) - surplus / base;
    }
};