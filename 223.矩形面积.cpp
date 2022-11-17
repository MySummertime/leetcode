#include <algorithm>


class Solution {
public:
    // geometry
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int s1 = (ax2 - ax1) * (ay2 - ay1);
        int s2 = (bx2 - bx1) * (by2 - by1);
        if (ax1 >= bx2 || ax2 <= bx1 || ay2 <= by1 || ay1 >= by2) {
            return s1 + s2;
        }
        // sum of area of two rectangles - area of overlap
        return s1 - (std::min(ax2, bx2) - std::max(ax1, bx1)) * (std::min(ay2, by2) - std::max(ay1, by1)) + s2;
    }
};