#include <vector>
#include <algorithm>


class UnionFind {
public:
    UnionFind(const int n): parent(n), rank(n) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    void uni(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx != ry) {
            if (rank[rx] > rank[ry]) {
                parent[ry] = rx;
            }
            else if (rank[rx] < rank[ry]) {
                parent[rx] = ry;
            }
            else {
                parent[ry] = rx;
                ++rank[rx];
            }
        }
    }

    int find(const int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

private:
    std::vector<int> parent;
    std::vector<int> rank;
};

class Solution {
public:
    // union find
    int largestComponentSize(std::vector<int>& nums) {
        int m = *std::max_element(nums.begin(), nums.end());
        UnionFind uf(1 + m);
        for (const int& num : nums) {
            for (int i = 2; i * i <= num; ++i) {
                if (num % i == 0) {
                    uf.uni(num, i);
                    uf.uni(num, num / i);
                }
            }
        }
        std::vector<int> cnt(1 + m, 0);
        int ans = 0;
        for (const int& i : nums) {
            int root = uf.find(i);
            ++cnt[root];
            ans = ans > cnt[root] ? ans : cnt[root];
        }
        return ans;
    }
};