#include <vector>

using std::vector;


class Solution {
public:
    // hash map
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        int mp1[128], mp2[128], mp3[128];
        memset(mp1, 0, sizeof(mp1));
        memset(mp2, 0, sizeof(mp2));
        memset(mp3, 0, sizeof(mp3));
        for (const int& i : nums1)  ++mp1[i];
        for (const int& i : nums2)  ++mp2[i];
        for (const int& i : nums3)  ++mp3[i];
        vector<int> ans;
        for (int i = 0, len = 128; i < len; ++i) {
            if (mp1[i] && (mp2[i] || mp3[i]))   ans.push_back(i);
            else if (mp2[i] && mp3[i])  ans.push_back(i);
        }
        return ans;
    }
};