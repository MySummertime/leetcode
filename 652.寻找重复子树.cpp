#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using std::vector;
using std::string;
using std::unordered_map;
using std::unordered_set;

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
    // dfs & serialization
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return {duplicate.begin(), duplicate.end()};
    }

private:
    string dfs(TreeNode* root) {
        if (!root)  return "";
        string serial = std::to_string(root->val) +"(" + dfs(root->left) + ")(" + dfs(root->right) + ")";
        if (auto it = vis.find(serial); it != vis.end()) {
            duplicate.insert(it->second);
        }
        else {
            vis[serial] = root;
        }
        return serial;
    }

private:
    unordered_map<string, TreeNode*> vis;
    unordered_set<TreeNode*> duplicate;
};