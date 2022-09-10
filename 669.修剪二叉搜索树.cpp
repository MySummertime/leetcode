/**
 * Definition for a binary tree node.
 */
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
    // pre-order
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return dfs(root, low, high);
    }

private:
    TreeNode* dfs(TreeNode* root, int l, int r) {
        if (!root)  return nullptr;
        if (l <= root->val && root->val <= r) {
            root->left = dfs(root->left, l, r);
            root->right = dfs(root->right, l, r);
            return root;
        }
        if (root->val < l) {
            return dfs(root->right, l, r);
        }
        return dfs(root->left, l, r);
    }
};