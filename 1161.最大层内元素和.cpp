#include <vector>
#include <iostream>

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
    // dfs + vector
    int maxLevelSum(TreeNode* root) {
        dfs(root, 0);
        int ans = 0;
        for (int i = 0, len = sum.size(); i < len; ++i) {
            if (sum[i] > sum[ans]) {
                ans = i;
            }
        }
        return ++ans;
    }

private:
    void dfs(TreeNode* root, int level) {
        if (!root) {
            return;
        }
        if (level == sum.size()) {
            sum.push_back(root->val);
        }
        else {
            sum[level] += root->val;
        }
        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
    }

private:
    std::vector<int> sum;
};
*/

class Solution {
public:
    // bfs
    int maxLevelSum(TreeNode* root) {
        int ans = 1;
        int max = INT32_MIN;
        bfs(root, ans, max);
        return ans;
    }

private:
    void bfs(TreeNode* root, int& ans, int& max) {
        std::vector<TreeNode*> cur {root};
        int level = 1;
        while (!cur.empty()) {
            std::vector<TreeNode*> next;
            int sum = 0;
            for (TreeNode* node : cur) {
                sum += node->val;
                if (node->left) {
                    next.push_back(node->left);
                }
                if (node->right) {
                    next.push_back(node->right);
                }
            }
            if (sum > max) {
                max = sum;
                ans = level;
            }
            cur = std::move(next);
            ++level;
        }
    }
};