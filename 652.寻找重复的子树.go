/**
 * Definition for a binary tree node.
 */
type TreeNode struct {
    Val int
    Left *TreeNode
    Right *TreeNode
}

// dfs & serialization
func findDuplicateSubtrees(root *TreeNode) []*TreeNode {
    vis := map[string]*TreeNode {}
    duplicate := map[*TreeNode]struct{} {}
    var dfs func(*TreeNode) string

    dfs = func(node *TreeNode) string {
        if node == nil {
            return ""
        }
        serial := fmt.Sprintf("%d(%s)(%s)", node.Val, dfs(node.Left), dfs(node.Right))
        if i, flag := vis[serial]; flag {
            duplicate[i] = struct{} {}
        }	else {
            vis[serial] = node
        }
        return serial
    }

    dfs(root)
    ans := make([]*TreeNode, 0, len(duplicate))
    for node := range duplicate {
        ans = append(ans, node)
    }
    return ans
}