#include <string>

using std::string;


class Solution {
public:
    // simulate
    string alphabetBoardPath(string target) {
        string ans;
        int x = 0, y = 0;
        for (auto& ch : target) {
            int nx = (ch - 'a') / 5;
            int ny = (ch - 'a') % 5;
            string vertical(std::abs(nx - x), "UD"[nx > x]);
            string horizontal(std::abs(ny - y), "LR"[ny > y]);
            ans += (ch != 'z' ? vertical + horizontal : horizontal + vertical);
            ans += "!";
            x = nx, y = ny;
        }
        return ans;
    }
};