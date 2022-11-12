
class Solution {
public:
    // dynamic programming
    int numTilings(int n) {
        return dp(0, n, 0);
    }

private:
    long dp(int i, const int& n, int prev) {
        if (i > n)  return 0;
        if (i == n) return !prev;
        if (vec[i][prev])    return vec[i][prev];
        if (prev) {
            return vec[i][prev] = (dp(i + 1, n, 0) + dp(i + 1, n, 1)) % MOD;
        }
        return vec[i][prev] = (dp(i + 1, n, 0) + dp(i + 2, n, 0) + 2 * dp(i + 2, n, 1)) % MOD;
    }

private:
    const int MOD = 1e9 + 7;
    int vec[1024][2];
};