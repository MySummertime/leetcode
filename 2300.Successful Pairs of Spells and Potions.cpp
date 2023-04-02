#include <vector>
#include <algorithm>

using std::vector;


class Solution_1 {
public:
    // sort && binary search
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        std::sort(potions.begin(), potions.end(), std::less<>());
        for (int& i : spells) {
            i = potions.end() - std::upper_bound(potions.begin(), potions.end(), (success - 1) / i);
        }
        return spells;
    }
};


class Solution_2 {
public:
    // sort && binary search [l, r)
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        std::sort(potions.begin(), potions.end(), std::less<>());
        ans.resize(spells.size(), 0);
        for (int i = 0, len = spells.size(); i < len; ++i) {
            ans[i] = binarySearch(potions, (double)success / spells[i]);
        }
        return ans;
    }

private:
    int binarySearch(const vector<int>& potions, const double& target) {
        int l = 0, len = potions.size(), r = len;
        int m;
        while (l < r) {
            m = l + ((r - l) >> 1);
            if (potions[m] < target) {
                l = m + 1;
            }
            else {
                r = m;
            }
        }
        return len - l;
    }

private:
    vector<int> ans;
};

