#include <stack>
#include <queue>
#include <vector>

using std::stack;
using std::queue;
using std::vector;


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
    // pre-order dfs
    TreeNode* invertTree(TreeNode* root) {
        dfs(root);
        return root;
    }

private:
    void dfs(TreeNode* root) {
        if (!root)  return;
        swapSubTree(root);  // mid
        dfs(root->left);    // left
        dfs(root->right);   // right
    }

    void swapSubTree(TreeNode* root) {
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
    }
};


class Solution_2_1 {
public:
    // pre-order iteration
    TreeNode* invertTree(TreeNode* root) {
        if (!root)  return nullptr;
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            for (int i = 0, len = stk.size(); i < len; ++i) {
                TreeNode* node = stk.top();
                stk.pop();
                swapSubTree(node);  // mid
                if (node->left) stk.push(node->left);   // left
                if (node->right)    stk.push(node->right);  // right
            }
        }
        return root;
    }

private:
    void swapSubTree(TreeNode* root) {
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
    }
};


class Solution_2_2 {
public:
    // pre-order iteration(common)
    TreeNode* invertTree(TreeNode* root) {
        if (!root)  return nullptr;
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode* node = stk.top();
            if (node) {
                stk.pop();
                if (node->right)    stk.push(node->right);  // right
                if (node->left) stk.push(node->left);   // left
                stk.push(node); // mid
                stk.push(nullptr);
            }
            else {
                stk.pop();
                node = stk.top();
                stk.pop();
                swapSubTree(node);
            }
        }
        return root;
    }

private:
    void swapSubTree(TreeNode* root) {
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
    }
};


class Solution_3 {
public:
    // traversal
    TreeNode* invertTree(TreeNode* root) {
        if (!root)  return nullptr;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            for (int i = 0, len = que.size(); i < len; ++i) {
                TreeNode* node = que.front();
                que.pop();
                swapSubTree(node);  // mid
                if (node->left) que.push(node->left);   // left
                if (node->right)    que.push(node->right);  // right
            }
        }
        return root;
    }

private:
    void swapSubTree(TreeNode* root) {
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
    }
};