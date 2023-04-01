#include <vector>

using std::vector;


class Solution_1 {
public:
    // binary search (l, r]
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        return binarySearch(nums, 0, len - 1, target);
    }

private:
    int binarySearch(const vector<int>& nums, int l, int r, const int& target) {
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
        return nums[l] == target ? l : -1;
    }
};


class Solution_2 {
public:
    // binary search [l, r)
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        return binarySearch(nums, 0, len - 1, target);
    }

private:
    int binarySearch(const vector<int>& nums, int l, int r, const int& target) {
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
        return nums[r] == target ? r : -1;
    }
};