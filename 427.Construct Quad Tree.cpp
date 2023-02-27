#include <vector>

using std::vector;


// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
public:
    // dfs && presum
    Node* construct(vector<vector<int>>& grid) {
        presum.resize(128, vector<int>(128, 0));
        g = grid;
        int len = g.size();
        for (int i = 1; i <= len; ++i) {
            for (int j = 1; j <= len; ++j) {
                presum[i][j] = presum[i - 1][j] + presum[i][j - 1] - presum[i - 1][j - 1] + g[i - 1][j - 1];
            }
        }
        return dfs(0, len - 1, 0, len - 1);
    }

private:
    Node* dfs(int xstart, int xend, int ystart, int yend) {
        int cur = presum[xend + 1][yend + 1] - presum[xstart][yend + 1] - presum[xend + 1][ystart] + presum[xstart][ystart];
        int dx = xend - xstart + 1;
        int dy = yend - ystart + 1;
        int total = dx * dy;
        // presum == 0 || presum == sum of count: find a leaf
        if (cur == 0 || cur == total)   return new Node(g[xstart][ystart] == 1, true);
        // not a leaf
        Node* root = new Node(g[xstart][ystart] == 1, false);
        int mx = xstart + ((xend - xstart) >> 1);
        int my = ystart + ((yend - ystart) >> 1);
        root->topLeft = dfs(xstart, mx, ystart, my);
        root->topRight = dfs(xstart, mx, my + 1, yend);
        root->bottomLeft = dfs(mx + 1, xend, ystart, my);
        root->bottomRight = dfs(mx + 1, xend, my + 1, yend);
        return root;
    }

private:
    vector<vector<int>> presum;
    vector<vector<int>> g;
};