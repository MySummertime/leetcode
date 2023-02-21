#include <vector>

using std::vector;


class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {

    }
};



class Solution {
public:
    // greedy
    int minTaps(int n, vector<int>& ranges) {
        int taps = 0;
        int mini = 0, maxi = 0; // initially both are zeros
        int last = 0;
        while (maxi < n) {
            for (int i = last; i <= n; ++i) {
                if (i - ranges[i] <= mini && i + ranges[i] > maxi) {
                    last = i;
                    maxi = i + ranges[i];
                }
            }
            // if garden cannot be watered
            if (maxi == mini)
                return -1;
            ++taps;
            mini = maxi;
        }
        return taps;
    }
};

