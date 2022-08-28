#include <string>

using std::string;

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
    // preorder dfs
    string tree2str(TreeNode* root) {
        dfs(root);
        int len = ans.length();
        return ans.substr(1, len - 2);
    }

private:
    void dfs(TreeNode* root) {
        ans.append("(");
        ans.append(std::to_string(root->val));
        if (root->left) {
            dfs(root->left);
        }
        else if (root->right) {
            ans.append("()");
        }
        if (root->right) {
            dfs(root->right);
        }
        ans.append(")");
    }

private:
    string ans;
};