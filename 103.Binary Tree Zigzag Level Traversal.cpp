#include <vector>
#include <queue>

using std::vector;
using std::queue;


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
    // traversal
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root)  return {};
        vector<vector<int>> ans;
        queue<TreeNode*> que;
        que.push(root);
        // true: turn right; left: turn left
        bool flag = false;
        while (!que.empty()) {
            int len = que.size();
            vector<int> vec(len);
            for (int i = 0; i < len; ++i) {
                TreeNode* node = que.front();
                que.pop();
                vec[i] = node->val;
                if (node->left) que.push(node->left);
                if (node->right)    que.push(node->right);
            }
            if (flag)   std::reverse(vec.begin(), vec.end());
            ans.push_back(vec);
            flag = !flag;
        }
        return ans;
    }
};