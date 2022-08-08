
#include <vector>
#include <string>

using std::vector;


class Solution {
public:
    // (divide & conquer) & binary search
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        // scale is even
        if ((total & 1) == 0) {
            int left = find(nums1, 0, nums2, 0, total >> 1);
            int right = find(nums1, 0, nums2, 0, ((total >> 1) + 1));
            return (left + right) / 2.0;
        }
        // scale is odd
        return find(nums1, 0, nums2, 0, (total >> 1) + 1);
    }

private:
    // i: the first idx of v1's valid scope
    // j: the first idx of v2's valid scope
    // k: the valid scope
    int find(vector<int> nums1, int i, vector<int> nums2, int j, int k) {
        int len1 = nums1.size();    int len2 = nums2.size();
        // To simplify border processing operations,
        // make the valid scale of v1 <= the scale of v2
        if (len1 - i > len2 - j) {
            return find(nums2, j, nums1, i, k);
        }
        if (i >= len1) {
            return nums2[j + k - 1];
        }
        if (k != 1) {
            int m1 = std::min(i + (k >> 1), len1);
            int m2 = j + k - (k >> 1);
            if (nums1[m1 - 1] > nums2[m2 - 1]) {
                return find(nums1, i, nums2, m2, k - (m2 - j));
            }
            else {
                return find(nums1, m1, nums2, j, k - (m1 - i));
            }
        }
        return std::min(nums1[i], nums2[j]);
    }
};


/**
class Solution {
public:
    // double pointers
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();    int n = nums2.size();
        // guarantee that len1 <= len2
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int left_len = (m + n + 1) >> 1;
        // search for the dividing line on the left side
        int l = 0;  int r = m;
        while (l < r) {
            int i = l + ((r - l) >> 1); // pointer of the first vector
            int j = left_len - i;   // pointer on the right side, indicating the first larger idx of the right side
            if (nums1[i] < nums2[j - 1]) {
                l = i + 1;
            }
            else {
                r = i;
            }
        }
        int i = l;  // the dividing line on the left side
        int j = left_len - i;   // the first larger idx of the right side
        //std::cout << std::to_string(i) << "\n" << std::to_string(j);
        int nums1_left_max = (i == 0) ? INT32_MIN : nums1[i - 1];
        int nums2_right_min = (j == n) ? INT32_MAX : nums2[j];
        int nums1_right_min = (i == m) ? INT32_MAX : nums1[i];
        int nums2_left_max = (j == 0) ? INT32_MIN : nums2[j - 1];
        if ((m + n) & 1) {
            return std::max(nums1_left_max, nums2_left_max);
        }
        return (double)(std::max(nums1_left_max, nums2_left_max) + std::min(nums1_right_min, nums2_right_min)) / 2;
    }
};
*/