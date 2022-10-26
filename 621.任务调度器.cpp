#include <vector>
#include <algorithm>

using std::vector;


class Solution {
public:
    // simulate
    int leastInterval(vector<char>& tasks, int n) {
        int len = tasks.size();
        vector<int> vec(26, 0);
        for (const char& c : tasks) {
            ++vec[c - 'A'];
        }
        std::sort(vec.begin(), vec.end(), [&] (int& a, int& b) -> bool {
            return a > b;
        });
        // find the largest frequency of elements
        int cnt = 1;
        while (cnt < vec.size() && vec[cnt] == vec[0]) {
            ++cnt;
        }
        return std::max(len, (vec[0] - 1) * (n + 1) + cnt);
    }
};