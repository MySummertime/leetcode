#include <vector>

using std::vector;

class Solution {
public:
    // merge sort
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }

private:
    void merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> vec(right - left + 1);
        int i = left, j = mid + 1, k = 0;
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                vec[k++] = nums[i++];
            }
            else {
                vec[k++] = nums[j++];
            }
        }
        while (i <= mid)    vec[k++] = nums[i++];
        while (j <= right)  vec[k++] = nums[j++];
        for (int p = 0; p < k; ++p) {
            nums[left + p] = vec[p];
        }
    }

    void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right)  return;
        int mid = (left + right) >> 1;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }
};