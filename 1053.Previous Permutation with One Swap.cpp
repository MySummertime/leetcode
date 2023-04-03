#include <vector>

using std::vector;


class Solution {
public:
    // greedy && two pointers
    vector<int> prevPermOpt1(vector<int>& arr) {
        int len = arr.size();
        for (int l = len - 1, idx, val; l >= 0; --l) {
            idx = -1, val = 0;
            for (int r = l + 1; r < len; ++r) {
                // find the leftmost idx of reversed orders
                if (arr[l] > arr[r]) {
                    // find the largest permutation
                    if (arr[r] > val) {
                        val = arr[r];
                        idx = r;
                    }
                }
            }
            if (idx == -1)  continue;
            else {
                std::swap(arr[l], arr[idx]);
                break;
            }
        }
        return arr;
    }
};