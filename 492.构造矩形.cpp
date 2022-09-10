#include <vector>

using std::vector;

class Solution {
public:
    // geometry math
    vector<int> constructRectangle(int area) {
        int w = sqrt(area);
        // find the first number that is divisible by area without a remainder
        while (area % w != 0) {
            --w;
        }
        return {area / w, w};
    }
};