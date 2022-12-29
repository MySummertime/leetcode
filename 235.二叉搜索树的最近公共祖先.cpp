

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
    // pre-order dfs
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)  return nullptr;
        int x = root->val;
        if (p->val < x && q->val < x)   return lowestCommonAncestor(root->left, p, q);
        if (p->val > x && q->val > x)   return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};