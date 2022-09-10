#include <vector>
#include <stack>
#include <unordered_map>

using std::vector;
using std::stack;
using std::unordered_map;


class Solution {
public:
    // monotinic stack & hash map
    vector<int> nextGreaterElement(vector<int>& subset, vector<int>& nums) {
        // construct a monotonic stack with push & pop
        for (const int& i : nums) {
            while (stk.size() && stk.top() < i) {
                m[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        int len = subset.size();
        vector<int> ans(len, -1);
        for (int i = 0; i < len; ++i) {
            auto itr = m.find(subset[i]);
            ans[i] = itr == m.end() ? -1 : itr->second;
        }
        return ans;
    }

private:
    stack<int> stk;
    unordered_map<int, int> m;
};