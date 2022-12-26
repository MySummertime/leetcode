#include <vector>

using std::vector;


/*
class Solution {
public:
    // binary search: (left, right)
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        return binarySearch(nums, -1, len - 1);
    }

private:
    int binarySearch(const vector<int>& nums, int l, int r) {
        int m;
        while (l + 1 < r) {
            m = l + ((r - l) >> 1);
            if (nums[m] > nums[m + 1]) {
                r = m;
            }
            else {
                l = m;
            }
        }
        return r;
    }
};
*/

/*
class Solution {
public:
    // binary search: [left, right)
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        return binarySearch(nums, 0, len - 1);
    }

private:
    int binarySearch(const vector<int>& nums, int l, int r) {
        int m;
        while (l < r) {
            m = l + ((r - l) >> 1);
            if (nums[m] > nums[m + 1]) {
                r = m;
            }
            else {
                l = m + 1;
            }
        }
        return r;
    }
};
*/


class Solution {
public:
    // binary search: (left, right]
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        return binarySearch(nums, 0, len - 1);
    }

private:
    int binarySearch(const vector<int>& nums, int l, int r) {
        int m;
        while (l < r) {
            m = l + ((r - l + 1) >> 1);
            if (nums[m] > nums[m - 1]) {
                l = m;
            }
            else {
                r = m - 1;
            }
        }
        return r;
    }
};
