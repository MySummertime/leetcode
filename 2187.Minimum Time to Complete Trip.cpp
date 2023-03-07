#include <vector>
#include <algorithm>

using std::vector;


class Solution {
public:
    // binary search
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l = 1;
        long long r = (long long) totalTrips * *std::max_element(time.begin(), time.end());
        return binarySearch(time, totalTrips, 0, r);
    }

private:
    long long binarySearch(const vector<int>& time, const int& totalTrips, long long l, long long r) {
        long long m;
        while (l < r) {
            m = l + ((r - l) >> 1);
            // m trips is enough or more
            if (check(time, totalTrips, m)) {
                r = m;
            }
            else {
                l = m + 1;
            }
        }
        return l;
    }

    bool check(const vector<int>& arr, const int& totalTrips, long long m) {
        long long cnt = 0;
        for (const int& i : arr) {
            cnt += m / i;
        }
        return cnt >= totalTrips;
    }
};