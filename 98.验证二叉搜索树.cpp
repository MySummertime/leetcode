#include <iostream>
#include <stack>

using std::stack;


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
    // post-order dfs
    bool isValidBST(TreeNode* root) {
        return dfs(root).second != LONG_MAX;
    }

private:
    std::pair<long, long> dfs(TreeNode* root) {
        if (!root)  return {LONG_MAX, LONG_MIN};
        auto[lmin, lmax] = dfs(root->left);
        auto[rmin, rmax] = dfs(root->right);
        long x = root->val;
        if (x <= lmax || rmin <= x) return {LONG_MIN, LONG_MAX};
        return {std::min(lmin, x), std::max(x, rmax)};
    }
};
*/

/*
class Solution {
public:
    // in-order dfs
    bool isValidBST(TreeNode* root) {
        if (!root)  return true;
        if (!isValidBST(root->left))    return false;
        if (root->val <= prev)  return false;
        prev = root->val;
        return isValidBST(root->right);
    }

private:
    long prev = LONG_MIN;
};
*/

/*
class Solution {
public:
    // pre-order dfs
    bool isValidBST(TreeNode* root, long left = LONG_MIN, long right = LONG_MAX) {
        if (!root)  return true;
        long x = root->val;
        return left < x && x < right && isValidBST(root->left, left, x) && isValidBST(root->right, x, right);
    }
};
*/


class Solution {
public:
    // traversion
    bool isValidBST(TreeNode* root) {
        if (!root)  return true;
        return bfs(root);
    }

private:
    bool bfs(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* cur = root, *prev = nullptr;
        while (cur || !stk.empty()) {
            if (cur) {
                stk.push(cur);
                cur = cur->left;    //left
            }
            else {
                cur = stk.top(); //mid
                stk.pop();
                if (prev && cur->val <= prev->val) {
                    return false;
                }
                prev = cur;
                cur = cur->right;   //right
            }
        }
        return true;
    }
};