#include <vector>
#include <algorithm>

using std::vector;


class Solution {
public:
    // two pointers
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        if (len < 3) {
            return INT32_MAX;
        }
        int ans = nums[0] + nums[1] + nums[len - 1];
        quickSort(nums);
        //std::sort(nums.begin(), nums.end(), std::less<>());
        for (int i = 0, l, r, sum; i < len - 2; ++i) {
            if (i && nums[i] == nums[i - 1])
                continue;
            l = i + 1, r = len - 1;
            while (l < r) {
                sum = nums[i] + nums[l] + nums[r];
                if (sum > target) {
                    --r;
                }
                else if (sum < target) {
                    ++l;
                }
                else {
                    return sum;
                }
                // acquire the closest sum
                if (std::abs(sum - target) < dif) {
                    dif = std::abs(sum - target);
                    ans = sum;
                }
            }
        }
        return ans;
    }

private:
    void quickSort(vector<int>& vec) {
        int len = vec.size();
        if (len < 2) {
            return;
        }
        sort(vec, 0, len - 1);
    }

    void sort(vector<int>& vec, int l, int r) {
        if (l >= r) {
            return;
        }
        int pivot = paritition(vec, l, r);
        sort(vec, l, pivot - 1);
        sort(vec, pivot + 1, r);
    }

    int paritition(vector<int>& vec, const int& l, const int& r) {
        int pivot = l;
        int idx = pivot + 1;
        for (int i = idx; i <= r; ++i) {
            if (vec[i] < vec[pivot]) {
                std::swap(vec[i], vec[idx]);
                ++idx;
            }
        }
        std::swap(vec[idx - 1], vec[pivot]);
        return idx - 1;
    }

private:
    int dif = INT32_MAX;
};