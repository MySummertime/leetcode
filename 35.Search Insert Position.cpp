#include <vector>

using std::vector;


class Solution_1 {
public:
    // binary search [l, r)
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size());
    }

private:
    int binarySearch(const vector<int>& nums, const int& target, int l, int r) {
        int m;
        while (l < r) {
            m = l + ((r - l) >> 1);
            if (nums[m] < target) {
                l = m + 1;
            }
            else {
                r = m;
            }
        }
        return r;
    }
};


class Solution_2 {
public:
    // binary search [l, r]
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size() - 1);
    }

private:
    int binarySearch(const vector<int>& nums, const int& target, int l, int r) {
        int m;
        while (l <= r) {
            m = l + ((r - l) >> 1);
            if (nums[m] < target) {
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        return l;
    }
}