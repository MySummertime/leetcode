#include <stack>
#include <queue>

using std::stack;
using std::queue;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution100_1 {
public:
    // postorder dfs recursion
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return dfs(p, q);
    }

private:
    bool dfs(TreeNode* _p, TreeNode* _q) {
        if (!_p && !_q) return true;
        else if (!_p || !_q || _p->val != _q->val)  return false;
        bool left = dfs(_p->left, _q->left);    // left
        bool right = dfs(_p->right, _q->right); // right
        return left && right;
    }
};


class Solution100_2 {
public:
    // postorder iteration
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q)   return true;
        else if (!p || !q || p->val != q->val)  return false;
        stack<TreeNode*> stk;
        stk.push(q);
        stk.push(p);
        while (!stk.empty()) {
            TreeNode* l = stk.top();
            stk.pop();
            TreeNode* r = stk.top();
            stk.pop();
            if (!l && !r)   continue;
            else if (!l || !r || l->val != r->val)  return false;
            stk.push(l->right); // right
            stk.push(r->right);
            stk.push(l->left);  // left
            stk.push(r->left);
        }
        return true;
    }
};



class Solution100_3 {
public:
    // bfs traversal
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q)   return true;
        else if (!p || !q || p->val != q->val)  return false;
        queue<TreeNode*> que;
        que.push(p);
        que.push(q);
        while (!que.empty()) {
            TreeNode* l = que.front();
            que.pop();
            TreeNode* r = que.front();
            que.pop();
            if (!l && !r)   continue;
            else if (!l || !r || l->val != r->val)  return false;
            que.push(l->left);  // left
            que.push(r->left);
            que.push(l->right); // right
            que.push(r->right);
        }
        return true;
    }
};