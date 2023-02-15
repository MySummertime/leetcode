#include <vector>

using std::vector;


class Solution {
public:
    // math
    bool isGoodArray(vector<int>& nums) {
        int g = 0;
        for (const int& i : nums) {
            g = gcd(g, i);
            if (g == 1) return true;
        }
        return false;
    }

private:
    int gcd(int a, int b) {
        while (a % b) {
            int tmp = a % b;
            a = b;
            b = tmp;
        }
    }
};