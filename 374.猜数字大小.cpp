
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    // binary search
    int guessNumber(int n) {
        int ans = binarySearch(0, n);
        return ans;
    }

private:
    int binarySearch(int l, long r) {
        int m;
        while (l < r) {
            m = l + ((r - l + 1) >> 1);
            // guess is higher
            if (guess(m) == -1) {
                r = m - 1;
            }
            // guess is lower or perfect
            else {
                l = m;
            }
        }
        return guess(l) == 0 ? l : -1;
    }
};