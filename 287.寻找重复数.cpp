#include <vector>

using std::vector;

class Solution {
public:
    // The pigeonhole principle & binary search
    int findDuplicate(vector<int>& nums) {
        return binarySearch(nums, 0, nums.size() - 1);
    }

private:
    int binarySearch(const vector<int>& vec, int l, int r) {
        int m, cnt;
        while (l < r) {
            m = l + ((r - l) >> 1);
            // the quantity of integers that are not larger than m
            cnt = 0;
            for (const int& i : vec) {
                if (i <= m) {
                    ++cnt;
                }
            }
            // narrow the searching scope
            if (cnt > m) {
                r = m;
            }
            else {
                l = m + 1;
            }
        }
        return l;
    }
};