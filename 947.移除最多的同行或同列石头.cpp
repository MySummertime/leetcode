#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;


class Solution {
public:
    // union find
    int removeStones(vector<vector<int>>& stones) {
        // initialize a union tree
        init();
        // add edges into union tree
        for (const vector<int>& vec : stones) {
            join(vec[0], vec[1] + 10000);
        }
        unordered_map<int, bool> umap;
        // store the edges
        for (const vector<int>& vec : stones) {
            umap[find(vec[0])] = true;
            umap[find(vec[1] + 10000)] = true;
        }
        return stones.size() - umap.size();
    }

private:
    // initialize a union tree
    void init() {
        for (int i = 0; i < SCALE; ++i) {
            father[i] = i;
        }
    }

    // search for the father of values
    int find(int u) {
        return u == father[u] ? u : father[u] = find(father[u]);
    }

    // add an edge(v->u) into union tree
    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return ;
        father[v] = u;
    }

    // check if u and v has the same father
    bool checkRoot(int u, int v) {
        u = find(u);
        v = find(v);
        return u == v;
    }

private:
    static constexpr int SCALE = 32768;
    int father[SCALE];
};