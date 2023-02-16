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

class Solution_1 {
public:
    // pre-order dfs
    int maxDepth(TreeNode* root) {
        ans = 0;
        if (!root)  return 0;
        dfs(root, 1);
        return ans;
    }

private:
    void dfs(TreeNode* root, int depth) {
        ans = std::max(ans, depth); // mid
        if (!root->left && !root->right)    return;
        if (root->left) {   // left
            ++depth;
            dfs(root->left, depth);
            // backtrack
            --depth;
        }
        if (root->right) {  // right
            ++depth;
            dfs(root->right, depth);
            // backtrack
            --depth;
        }
    }

private:
    int ans;
};


class Solution_2 {
public:
    // post-order dfs
    int maxDepth(TreeNode* root) {
        if (!root)  return 0;
        return dfs(root);
    }

private:
    int dfs(TreeNode* root) {
        if (!root)  return 0;
        int left = dfs(root->left); // left
        int right = dfs(root->right);   // right
        int depth = 1 + std::max(left, right);
        return depth;
    }
};

class Solution_3 {
public:
    // traversal
    int maxDepth(TreeNode* root) {
        if (!root)  return 0;
        int ans = 0;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            ++ans;
            for (int i = 0, len = que.size(); i < len; ++i) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left) que.push(node->left);   // left
                if (node->right)    que.push(node->right);  // right
            }
        }
        return ans;
    }
};