#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

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
    // dfs
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return ans;
    }

private:
    string dfs(TreeNode* root) {
        if (!root)  return " ";
        string cur = std::to_string(root->val) + "_";   // mid
        //std::cout << cur << ",";
        string left = dfs(root->left);  // left
        string right = dfs(root->right);    // right
        cur += left + right;
        ++ump[cur];
        //std::cout << cur << std::endl;
        if (ump[cur] == 2)   ans.push_back(root);
        return cur;
    }

private:
    unordered_map<string, int> ump;
    vector<TreeNode*> ans;
};