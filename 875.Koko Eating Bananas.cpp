#include <vector>
#include <algorithm>

using std::vector;


class Solution {
public:
    // binary search
    int minEatingSpeed(vector<int>& piles, int h) {
        int maximum = *std::max_element(piles.begin(), piles.end());
        return binarySearch(piles, h, 1, maximum);
    }

private:
    int binarySearch(const vector<int>& piles, const int& h, int l, int r) {
        int m;
        while (l < r) {
            m = l + ((r - l) >> 1);
            if (valid(piles, h, m)) {
                r = m;
            }
            else {
                l = m + 1;
            }
        }
        return l;
    }

private:
    bool valid(const vector<int>& piles, const int& h, int m) {
        long cnt = 0;
        for (const int& i : piles) {
            cnt += long((i + m - 1) / m);
        }
        return cnt <= h;
    }
};