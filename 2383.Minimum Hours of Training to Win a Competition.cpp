#include <vector>

using std::vector;


class Solution {
public:
    // greedy
    int minNumberOfHours(int ienergy, int iexperience, vector<int>& energy, vector<int>& experience) {
        int ans = 0;
        for (int i = 0, len = energy.size(), t; i < len; i++) {
            if (ienergy <= energy[i]) {
                t = energy[i] - ienergy + 1;
                ienergy += t;
                ans += t;
            }
            if (iexperience <= experience[i]) {
                t = experience[i] - iexperience + 1;
                iexperience += t;
                ans += t;
            }
            ienergy -= energy[i];
            iexperience += experience[i];
        }
        return ans;
    }
};