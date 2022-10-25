#include <vector>
#include <string>
#include <functional>

using std::vector;
using std::string;


class Solution {
public:
    // backtrack & bit operation
    int maxLength(vector<string>& arr) {
        vector<int> vec;
        for (string& s : arr) {
            int mask = 0;
            for (char c : s) {
                c -= 'a';
                if ((mask >> c) & 1) {
                    mask = 0;
                    break;
                }
                mask |= (1 << c);
            }
            if (mask) {
                vec.emplace_back(mask);
            }
        }
        int ans = 0;

        std::function<void(int, int)> backtrack = [&] (int idx, int mask) {
            if (idx == vec.size()) {
                ans = std::max(ans, __builtin_popcount(mask));
                return;
            }
            if ((mask & vec[idx]) == 0) {
                backtrack(idx + 1, mask | vec[idx]);
            }
            backtrack(idx + 1, mask);
        };

        backtrack(0, 0);
        return ans;
    }
};