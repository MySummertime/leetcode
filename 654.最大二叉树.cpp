#include <vector>

using namespace std;


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
    // pre-order dfs
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (!nums.size()) {
            return nullptr;
        }
        return dfs(nums, 0, nums.size());
    }

private:
    TreeNode* dfs(const vector<int>& nums, int l, int r) {
        if (l >= r) {
            return nullptr;
        }
        // update the current largest element
        int idx = l;
        for (int i = idx + 1; i < r; ++i) {
            if (nums[i] > nums[idx]) {
                idx = i;
            }
        }
        // [left, right)
        TreeNode* root = new TreeNode(nums[idx]);
        root->left = dfs(nums, l, idx);
        root->right = dfs(nums, idx + 1, r);
        return root;
    }
};