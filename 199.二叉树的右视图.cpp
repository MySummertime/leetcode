#include <vector>

using std::vector;


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
    // recursion
    vector<int> rightSideView(TreeNode* root) {
        depth = 0;
        vector<int> ans;
        recursion(ans, root);
        return ans;
    }

private:
    void recursion(vector<int>& ans, TreeNode* root) {
        if (!root)  return;
        if (depth == ans.size()) {
            ans.push_back(root->val);
        }
        ++depth;
        recursion(ans, root->right);
        recursion(ans, root->left);
    }

private:
    int depth;
};