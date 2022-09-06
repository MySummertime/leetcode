/**
 * Definition for a binary tree node.
 */
type TreeNode struct {
    Val int
    Left *TreeNode
    Right *TreeNode
}

// recursion
func pruneTree(root *TreeNode) *TreeNode {
	if root == nil {
		return nil
	}
	left, right := pruneTree(root.Left), pruneTree(root.Right)
	if left == nil && right == nil && root.Val == 0 {
		return nil
	}
	return &TreeNode{root.Val, left, right}
}