#include <vector>
#include <string>
#include <unordered_map>

using std::vector;
using std::string;
using std::unordered_map;


class Solution {
public:
    // gcd && unordered_map && traversal
    int maxPoints(vector<vector<int>>& points) {
        int len = points.size();
        int ans = 1;
        for (int i = 0; i < len; ++i) {
            unordered_map<string, int> mp;
            int cnt = 0;
            for (int j = i + 1; j < len; ++j) {
                int x1 = points[i][0], x2 = points[j][0];
                int y1 = points[i][1], y2 = points[j][1];
                int a = x1 - x2, b = y1 - y2;
                int k = gcd(a, b);
                string key = std::to_string(a / k) + "_" + std::to_string(b / k);
                if (mp.find(key) == mp.end()) {
                    mp[key] = 1;
                }
                else {
                    ++mp[key];
                }
                cnt = std::max(cnt, mp[key]);
            }
            ans = std::max(ans, cnt + 1);
        }
        return ans;
    }

private:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};