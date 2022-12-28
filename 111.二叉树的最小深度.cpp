#include <algorithm>
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
    // post-order recursion
    int minDepth(TreeNode* root) {
        if (!root)  return 0;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        if (!root->left && root->right) {
            return right + 1;
        }
        if (!root->right && root->left) {
            return left + 1;
        }
        int ans = std::min(left, right) + 1;
        return ans;
    }
};
*/


class Solution {
public:
    // traversal
    int minDepth(TreeNode* root) {
        if (!root)  return 0;
        queue<TreeNode*> que;
        que.push(root);
        int depth = 0;
        while (!que.empty()) {
            ++depth;
            for (int i = 0, scale = que.size(); i < scale; ++i) {
                TreeNode* node = que.front();
                que.pop();
                if (!node->left && !node->right)    return depth;
                if (node->left) {
                    que.push(node->left);
                }
                if (node->right) {
                    que.push(node->right);
                }
            }
        }
        return depth;
    }
};