
#include <vector>
#include <string>

using std::vector;


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

