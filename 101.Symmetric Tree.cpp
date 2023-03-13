#include <queue>

using std::queue;


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

class Solution_1 {
public:
    // recursion
    bool isSymmetric(TreeNode* root) {
        return recursion(root->left, root->right);
    }

private:
    bool recursion(TreeNode* left, TreeNode* right) {
        if (!left && !right)    return true;
        if (!left || !right)    return false;
        return left->val == right->val && recursion(left->left, right->right) && recursion(left->right, right->left);
    }
};


class Solution_2 {
public:
    // iteration
    bool isSymmetric(TreeNode* root) {
        if (!root)  return true;
        if (!root->left && !root->right)    return true;
        if (!root->left || !root->right)    return false;
        return iteration(root);
    }

private:
    bool iteration(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root->left);
        que.push(root->right);
        while (!que.empty()) {
            TreeNode* l = que.front();  que.pop();
            TreeNode* r = que.front();  que.pop();
            if (!l && !r)   continue;
            if (!l || !r)   return false;
            if (l->val != r->val)   return false;
            que.push(l->left);
            que.push(r->right);
            que.push(l->right);
            que.push(r->left);
        }
        return true;
    }
};