#include <vector>

using std::vector;


class Solution1 {
public:
    // recursion
    int minMaxGame(vector<int>& nums) {
        return recursion(nums);
    }

private:
    int recursion(vector<int>& nums) {
        int len = nums.size();
        if (len == 1)   return nums[0];
        vector<int> vec(len >> 1);
        for (int i = 0; i < vec.size(); ++i) {
            if (i % 2) {
                vec[i] = std::max(nums[i * 2], nums[i * 2 + 1]);
            }
            else {
                vec[i] = std::min(nums[i * 2], nums[i * 2 + 1]);
            }
        }
        return recursion(vec);
    }
};




class Solution2 {
public:
    // simulate
    int minMaxGame(vector<int>& nums) {
        int len = nums.size();
        while (len != 1) {
            vector<int> vec(len >> 1);
            for (int i = 0; i < vec.size(); ++i) {
                if (i & 1) {
                    vec[i] = std::max(nums[i * 2], nums[i * 2 + 1]);
                }
                else {
                    vec[i] = std::min(nums[i * 2], nums[i * 2 + 1]);
                }
            }
            nums = std::move(vec);
            len >>= 1;
        }
        return nums[0];
    }
};