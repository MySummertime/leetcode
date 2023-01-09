#include <vector>
#include <stack>

using std::vector;
using std::stack;


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


class Solution1 {
public:
    // preorder dfs recursion
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root)  return {};
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }

private:
    void dfs(TreeNode* root, vector<int>& ans) {
        if (!root)  return;
        ans.push_back(root->val);   // mid
        dfs(root->left, ans);
        dfs(root->right, ans);
    }
};


class Solution2 {
public:
    // preorder iteration
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root)  return {};
        vector<int> ans;
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            int len = stk.size();
            for (int i = 0; i < len; ++i) {
                TreeNode* cur = stk.top();
                stk.pop();
                ans.push_back(cur->val);    // mid
                if (cur->right) stk.push(cur->right);   // right
                if (cur->left)  stk.push(cur->left);    // left
            }
        }
        return ans;
    }
};