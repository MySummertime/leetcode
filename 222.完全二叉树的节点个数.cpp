#include <algorithm>
#include <queue>

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

/**
class Solution {
public:
    // post-order dfs
    int countNodes(TreeNode* root) {
        return dfs(root);
    }

private:
    int dfs(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int left = dfs(root->left);
        int right = dfs(root->right);
        int cnt = 1 + left + right;
        return cnt;
    }
};
*/

/**
class Solution {
public:
    // pre-order dfs
    int countNodes(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }

private:
    void dfs(TreeNode* root, int& ans) {
        if (!root) {
            return;
        }
        ++ans;
        if (root->left) {
            dfs(root->left, ans);
        }
        if (root->right) {
            dfs(root->right, ans);
        }
        return;
    }
};
*/

/**
class Solution {
public:
    // bfs traversal
    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int cnt = 0;
        bfs(root, cnt);
        return cnt;
    }

private:
    void bfs(TreeNode* root, int& cnt) {
        std::queue<TreeNode*> que;
        if (root) {
            que.push(root);
        }
        while (!que.empty()) {
            for (int i = 0, len = que.size(); i < len; ++i) {
                TreeNode* node = que.front();
                que.pop();
                ++cnt;
                if (node->left) {
                    que.push(node->left);
                }
                if (node->right) {
                    que.push(node->right);
                }
            }
        }
    }
};
*/

/**
class Solution {
public:
    // utilize attr of complete binary tree
    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int lheight = 0;
        int rheight = 0;
        TreeNode* lchild = root->left;
        TreeNode* rchild = root->right;
        while (lchild) {
            lchild = lchild->left;
            ++lheight;
        }
        while (rchild) {
            rchild = rchild->right;
            ++rheight;
        }
        if (lheight == rheight) {
            return (2 << lheight) - 1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
*/

class Solution {
public:
    // binary search
    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int depth = 0;
        TreeNode* child = root;
        while (child->left) {
            child = child->left;
            ++depth;
        }
        int l = 1 << depth;
        int r = (1 << (1 + depth)) - 1;
        while (l < r) {
            int m = l + ((r - l + 1) >> 1);
            if (exist(root, depth, m)) {
                l = m;
            }
            else {
                r = m - 1;
            }
        }
        return l;
    }

private:
    bool exist(TreeNode* root, int depth, int k) {
        int bits = 1 << (depth - 1);
        TreeNode* node = root;
        while (node && bits) {
            if (!(bits & k)) {
                node = node->left;
            }
            else {
                node = node->right;
            }
            bits >>= 1;
        }
        return node;
    }
};