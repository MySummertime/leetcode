#include <vector>
#include <stack>

using std::vector;
using std::stack;


class Solution {
public:
    // monotonic stack
    int sumSubarrayMins(vector<int>& arr) {
        arr.push_back(-1);
        long ans = 0L;
        stack<int> stk;
        stk.push(-1);
        for (int r = 0, l; r < arr.size(); ++r) {
            while (stk.size() > 1 && arr[r] <= arr[stk.top()]) {
                l = stk.top();
                stk.pop();
                ans += (long) arr[l] * (l - stk.top()) * (r - l);
            }
            stk.push(r);
        }
        return ans % MOD;
    }

private:
    static constexpr int MOD = 1e9 + 7;
};