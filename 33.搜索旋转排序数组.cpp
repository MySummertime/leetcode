#include <vector>

using std::vector;


class Solution {
public:
    // binary search: (left, right)
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        return binarySearch(nums, -1, len - 1, target);
    }

private:
    int binarySearch(const vector<int>& nums, int l, int r, const int& target) {
        int m;
        while (l + 1 < r) {
            m = l + ((r - l) >> 1);
            if (isBlue(nums, m, target)) {
                r = m;
            }
            else {
                l = m;
            }
        }
        if (r == nums.size() || nums[r] != target)  return -1;
        return r;
    }

    bool isBlue(const vector<int>& nums, int i, const int& target) {
        if (nums[i] > nums.back())
            return target > nums.back() && nums[i] >= target;
        return target > nums.back() || nums[i] >= target;
    }
};