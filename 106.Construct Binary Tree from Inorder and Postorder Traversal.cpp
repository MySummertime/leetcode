#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

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

class Solution {
public:
    // recursion
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        post_idx = postorder.size() - 1;
        int idx = 0;
        for (const int &i : inorder) {
            ump[i] = idx++;
        }
        return recursion(inorder, postorder, 0, inorder.size() - 1);
    }

private:
    TreeNode* recursion(const vector<int>& inorder, const vector<int>& postorder, int in_left, int in_right) {
        if (in_left > in_right)   return nullptr;
        int root_val = postorder[post_idx--];
        TreeNode* root = new TreeNode(root_val);
        int mid_idx = ump[root_val];
        root->right = recursion(inorder, postorder, mid_idx + 1, in_right);
        root->left = recursion(inorder, postorder, in_left, mid_idx - 1);
        return root;
    }

private:
    int post_idx;
    unordered_map<int, int> ump;
};