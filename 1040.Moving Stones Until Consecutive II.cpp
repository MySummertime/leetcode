#include <vector>
#include <algorithm>

using std::vector;


class Solution {
public:
    // two pointers
    vector<int> numMovesStonesII(vector<int>& stones) {
        // Sort the stones in ascending order
        std::sort(stones.begin(), stones.end(), std::less<>());
        int len = stones.size();
        if (stones[len - 1] - stones[0] + 1 == len) {
            return {0, 0};
        }
        // Initialize the maximum moves
        int max_moves = std::max(stones[len - 2] - stones[0] + 1, stones[len - 1] - stones[1] + 1) - (len - 1);

        // Initialize the pointers and the minimum moves
        int min_moves = len;
        int left = 0, right = 0;

        for (int left = 0, right = 0; left < len && right + 1 < len; ++left) {
            while (right + 1 < len && stones[right + 1] - stones[left] + 1 <= len) {
                ++right;
            }
            if (right - left + 1 == len - 1 && stones[right] - stones[left] + 1 == len - 1) {
                min_moves = std::min(min_moves, 2);
            }
            else {
                min_moves = std::min(min_moves, len - (right - left + 1));
            }
        }
        return {min_moves, max_moves};
    }
};