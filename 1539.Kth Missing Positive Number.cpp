#include <vector>
#include <iostream>

using std::vector;


class Solution {
public:
    // binary search
    int findKthPositive(vector<int>& arr, int k) {
        int len = arr.size();
        if (!len)   return INT32_MIN;
        if (arr[0] > k) return k;
        return binarySearch(arr, k, 0, len);
    }

private:
    int binarySearch(const vector<int>& arr, const int& k, int l, int r) {
        int m;
        while (l < r) {
            m = l + ((r - l) >> 1);
            if (arr[m] - (m + 1) < k) {
                l = m + 1;
            }
            else {
                r = m;
            }
        }
        return l + k;
    }
};