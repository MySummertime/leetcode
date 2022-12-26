#include <vector>

using std::vector;


/*
class Solution {
public:
    // binary search: [left, right)
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        int a = binarySearchLowerBound(nums, 0, len - 1, target);
        if (a == len || nums[a] != target)  return {-1, -1};
        int b = binarySearchUpperBound(nums, 0, len - 1, target);
        return {a, b};
    }

private:
    int binarySearchLowerBound(const vector<int>& nums, int l, int r, const int& target) {
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
        return l;
    }

    int binarySearchUpperBound(const vector<int>& nums, int l, int r, const int& target) {
        int m;
        while (l < r) {
            m = l + ((r - l + 1) >> 1);
            if (nums[m] > target) {
                r = m - 1;
            }
            else {
                l = m;
            }
        }
        return r;
    }
};
*/

class Solution {
public:
    // binary search: [left, right]
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        int a = binarySearchLowerBound(nums, 0, len - 1, target);
        if (a == len || nums[a] != target)  return {-1, -1};
        int b = binarySearchUpperBound(nums, 0, len - 1, target);
        return {a, b};
    }

private:
    int binarySearchLowerBound(const vector<int>& nums, int l, int r, const int& target) {
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

    int binarySearchUpperBound(const vector<int>& nums, int l, int r, const int& target) {
        int m;
        while (l <= r) {
            m = l + ((r - l) >> 1);
            if (nums[m] > target) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return r;
    }
};