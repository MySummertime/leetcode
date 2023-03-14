

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
    // pre-order dfs
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }

private:
    int dfs(TreeNode* root, int pre) {
        if (!root)  return 0;
        int sum = 10 * pre + root->val;
        if (!root->left && !root->right) {
            return sum;
        }
        int left = dfs(root->left, sum);
        int right = dfs(root->right, sum);
        return left + right;
    }
};