#include <unordered_map>

using std::unordered_map;
using ULL = unsigned long long;


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
    int widthOfBinaryTree(TreeNode* root) {
        ans = 0;
        dfs(root, 0, ULL(1));
        return ans;
    }

private:
    void dfs(TreeNode* root, int depth, ULL(idx)) {
        if (!root) {
            return;
        }
        // if depth is new, then add {depth, idx} to the map
        if (m.find(depth) == m.end()) {
            m[depth] = idx;
        }
        // because of pre-order recursion, current idx > m[depth] strictly
        ans = std::max(ans, idx - m[depth] + ULL(1));
        dfs(root->left, depth + 1, idx << 1);
        dfs(root->right, depth + 1, (idx << 1) | 1);
    }

private:
    // key: depth of the node
    // val: index of the node
    unordered_map<int, ULL> m;
    ULL ans;
};