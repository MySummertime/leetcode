#include <iostream>


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
    // in-order dfs
    int minDiffInBST(TreeNode* root) {
        int ans = INT32_MAX;
        int prev = -1;
        dfs(root, prev, ans);
        return ans;
    }

private:
    void dfs(TreeNode* root, int& prev, int& ans) {
        if (!root)  return;
        dfs(root->left, prev, ans); // left
        if (prev != -1) {  // mid
            ans = std::min(ans, root->val - prev);
        }
        prev = root->val;
        dfs(root->right, prev, ans);    // right
    }
};