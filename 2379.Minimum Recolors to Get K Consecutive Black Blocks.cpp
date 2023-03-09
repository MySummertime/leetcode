#include <string>

using std::string;


class Solution_1 {
public:
    // sliding window
    int minimumRecolors(string blocks, int k) {
        // white: 1; black: 0
        int cnt_white = 0;
        for (int i = 0; i < k; ++i) {
            cnt_white += blocks[i] & 1;
        }
        int ans = cnt_white;
        for (int i = k, len = blocks.length(); i < len; ++i) {
            cnt_white += (blocks[i] & 1) - (blocks[i - k] & 1);
            ans = std::min(ans, cnt_white);
        }
        return ans;
    }
};


class Solution_2 {
public:
    // sliding window
    int minimumRecolors(string blocks, int k) {
        int l = 0, r = 0, cnt = 0;
        while (r < k) {
            cnt += blocks[r] == 'W' ? 1 : 0;
            ++r;
        }
        int ans = cnt;
        while (r < blocks.length()) {
            cnt += blocks[r] == 'W' ? 1 : 0;
            cnt -= blocks[l] == 'W' ? 1 : 0;
            ans = std::min(ans, cnt);
            ++r;
            ++l;
        }
        return ans;
    }
};