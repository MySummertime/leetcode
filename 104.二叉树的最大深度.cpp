#include <algorithm>

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
    int maxDepth(TreeNode* root) {
        if (!root)  return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return std::max(left, right) + 1;
    }
};
*/

class Solution {
public:
    // recursion
    int maxDepth(TreeNode* root) {
        depth = 0;
        f(root, 0);
        return depth;
    }

private:
    void f(TreeNode* root, int cnt) {
        if (!root)  return;
        ++cnt;
        depth = std::max(depth, cnt);
        f(root->left, cnt);
        f(root->right, cnt);
    }

private:
    int depth;
};