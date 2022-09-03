#include <vector>

using std::vector;

class Solution {
public:
    // bfs
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans {1, 2, 3, 4, 5, 6, 7, 8, 9};
        for (int i = 2; i <= n; ++i) {
            vector<int> val;
            for (int n : ans) {
                int m = n % 10;
                if (m + k < 10) {
                    val.emplace_back(n * 10 + m + k);
                }
                if (k && m - k >= 0) {
                    val.emplace_back(n * 10 + m - k);
                }
            }
            ans = val;
        }
        return ans;
    }
};