#include <vector>
#include <algorithm>

using std::vector;


class Solution {
public:
    // sort && greedy
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        std::sort(seats.begin(), seats.end(), std::less<>());
        std::sort(students.begin(), students.end(), std::less<>());
        int ans = 0;
        for (int i = 0, len = seats.size(); i < len; ++i) {
            ans += std::abs(seats[i] - students[i]);
        }
        return ans;
    }
};