#include <vector>

using std::vector;


class Solution {
public:
    // math
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        for (int len = num.size(), i = len - 1, cur, mod; i >= 0; --i) {
            mod = k % 10;
            k /= 10;
            cur = num[i] + mod;
            if (cur >= 10) {
                cur -= 10;
                ++k;
            }
            ans.push_back(cur);
        }
        while (k) {
            ans.push_back(k % 10);
            k /= 10;
        }
        return vector<int>(ans.rbegin(), ans.rend());
    }
};