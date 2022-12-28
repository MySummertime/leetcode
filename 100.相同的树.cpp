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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q)   return true;
        if (!p || !q)   return false;
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
*/


class Solution {
public:
    // traversion
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return traversion(p, q);
    }

private:
    bool traversion(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> que;
        que.push(p);
        que.push(q);
        while (!que.empty()) {
            TreeNode* l = que.front();  que.pop();
            TreeNode* r = que.front();  que.pop();
            if (!l && !r)   continue;
            if (!l || !r)   return false;
            if (l->val != r->val)   return false;
            que.push(l->left);  que.push(r->left);
            que.push(l->right); que.push(r->right);
        }
        return true;
    }
};