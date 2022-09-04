#include <vector>
#include <map>
#include <set>

using std::vector;
using std::map;
using std::multiset;

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
    // in-order dfs
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> m;
        dfs(root, 0, 0, m);
        vector<vector<int>> ans;
        for (auto& p : m) {
            vector<int> tmp;
            for (auto& q : p.second) {
                tmp.insert(tmp.end(), q.second.begin(), q.second.end());
            }
            ans.emplace_back(tmp);
        }
        return ans;
    }

private:
    void dfs(TreeNode* root, int x, int y, map<int, map<int, multiset<int>>>& m) {
        if (!root)  return;
        m[x][y].insert(root->val);
        dfs(root->left, x - 1, y + 1, m);
        dfs(root->right, x + 1, y + 1, m);
    }
};