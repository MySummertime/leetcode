/*
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
*/


#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>

using std::vector;
using std::priority_queue;

class Solution {
public:
    // customized sort & greater-than queue
    double mincostToHireWorkers(vector<int>& q, vector<int>& w, int k) {
        vector<int> id(q.size(), 0);
        std::iota(id.begin(), id.end(), 0);
        // customized sort: cost ascending
        std::sort(id.begin(), id.end(), [&] (const int& i, const int& j) -> bool {
            return w[i] * q[j] < w[j] * q[i];
        });
        // the lowest sum of cost
        int sum_q = 0;
        priority_queue<int, vector<int>, std::less<>()> pq;
        // firstly, choose k labours
        for (int i = 0; i < k; ++i) {
            pq.push(q[id[i]]);
            sum_q += q[id[i]];
        }
        double ans = sum_q * ((double)w[id[k - 1]] / q[id[k - 1]]);
        // then, update the queue if remaining labours are cheaper than the chosen ones
        for (int i = k, len = q.size(); i < len; ++i) {
            // check if the current cost can be lower
            if (q[id[i]] < pq.top()) {
                sum_q -= pq.top() - q[id[i]];
                pq.pop();
                pq.push(q[id[i]]);
                ans = std::min(ans, sum_q * ((double)w[id[i]] / q[id[i]]));
            }
        }
        return ans;
    }
};
