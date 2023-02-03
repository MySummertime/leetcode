#include <algorithm>
#include <functional>



// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // dfs
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        int lsz, rsz;

        std::function<int(TreeNode*)> dfs = [&] (TreeNode *node) {
            if (!node)
                return 0;
            int ls = dfs(node->left);
            int rs = dfs(node->right);
            if (node->val == x)
                lsz = ls, rsz = rs;
            return ls + rs + 1;
        };

        dfs(root);
        return std::max({lsz, rsz, n - 1 - lsz - rsz}) * 2 > n;
    }
};