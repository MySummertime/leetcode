#include <vector>

using std::vector;


/*
class Solution {
public:
    // binary search: (left, right)
    int findMin(vector<int>& nums) {
        int len = nums.size();
        return nums[binarySearch(nums, -1, len - 1)];
    }

private:
    int binarySearch(const vector<int>& nums, int l, int r) {
        int m;
        while (l + 1 < r) {
            m = l + ((r - l) >> 1);
            if (nums[m] < nums.back()) {
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
    int findMin(vector<int>& nums) {
        int len = nums.size();
        return nums[binarySearch(nums, 0, len - 1)];
    }

private:
    int binarySearch(const vector<int>& nums, int l, int r) {
        int m;
        while (l < r) {
            m = l + ((r - l) >> 1);
            if (nums[m] < nums[r]) {
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
    int findMin(vector<int>& nums) {
        int len = nums.size();
        return nums[binarySearch(nums, 0, len - 1)];
    }

private:
    int binarySearch(const vector<int>& nums, int l, int r) {
        int m;
        while (l < r) {
            m = l + ((r - l + 1) >> 1);
            if (nums[m] < nums[0]) {
                r = m - 1;
            }
            else {
                l = m;
            }
        }
        return r + 1 < nums[0] ? r + 1 : 0;
    }
};