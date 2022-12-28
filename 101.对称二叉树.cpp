#include <queue>

using std::queue;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
class Solution {
public:
    // recursion
    bool isSymmetric(TreeNode* root) {
        return recursion(root->left, root->right);
    }

private:
    bool recursion(TreeNode* p, TreeNode* q) {
        if (!p && !q)   return true;
        if (!p || !q)   return false;
        return p->val == q->val && recursion(p->left, q->right) && recursion(p->right, q->left);
    }
};
*/

class Solution {
public:
    // iteration
    bool isSymmetric(TreeNode* root) {
        return iteration(root->left, root->right);
    }

private:
    bool iteration(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> que;
        que.push(p);
        que.push(q);
        while (!que.empty()) {
            TreeNode* l = que.front();  que.pop();
            TreeNode* r = que.front();  que.pop();
            if (!l && !r)   continue;
            if (!l || !r)   return false;
            if (l->val != r->val)   return false;
            que.push(l->right); que.push(r->left);
            que.push(l->left);  que.push(r->right);
        }
        return true;
    }
};