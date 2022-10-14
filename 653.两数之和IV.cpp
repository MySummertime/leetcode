#include <unordered_set>
#include <vector>

using std::unordered_set;
using std::vector;


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
    // inorder dfs & binary search
    bool findTarget(TreeNode* root, int k) {
        dfs(root);
        return binarySearch(0, vec.size() - 1, k);
    }

private:
    // store the inorder traversal result in vec
    void dfs(TreeNode* root) {
        if (!root)  return;
        dfs(root->left);
        vec.emplace_back(root->val);
        dfs(root->right);
    }

    bool binarySearch(int l, int r, const int& target) {
        while (l < r) {
            if (vec[l] + vec[r] == target)  return true;
            else if (vec[l] + vec[r] < target) {
                ++l;
            }
            else {
                --r;
            }
        }
        return false;
    }

private:
    vector<int> vec;
};


/*
class Solution {
public:
    // preorder dfs & set
    bool findTarget(TreeNode* root, int k) {
        return dfs(root, k);
    }

private:
    bool dfs(TreeNode* root, const int& target) {
        if (!root)  return false;
        if (st.find(target - root->val) != st.end())    return true;
        st.insert(root->val);
        return dfs(root->left, target) || dfs(root->right, target);
    }

private:
    unordered_set<int> st;
};
*/

