
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
    // post order dfs
    bool evaluateTree(TreeNode* root) {
        return dfs(root);
    }

private:
    bool dfs(TreeNode* root) {
        if (!root->left && !root->right) {
            return root->val == 1;
        }
        bool left = dfs(root->left);
        bool right = dfs(root->right);
        bool ans = root->val == 3 ? left && right : left || right;
        return ans;
    }
};