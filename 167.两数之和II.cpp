#include <vector>

using std::vector;


class Solution {
public:
    // two pointers
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = numbers.size();
        int l = 0, r = len - 1, s;
        while (true) {
            s = numbers[l] + numbers[r];
            if (s == target)    break;
            if (s > target) --r;
            if (s < target) ++l;
        }
        return {l + 1, r + 1};
    }
};