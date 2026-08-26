/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func flatten(root *TreeNode) {
	var temp *TreeNode

	var dfs func(node *TreeNode)
	dfs = func(node *TreeNode) {
		if node == nil {
			return
		}
		left := node.Left
		right := node.Right

		if temp != nil {
			temp.Right = node
		}
		node.Left = nil
		temp = node
		dfs(left)
		dfs(right)
	}

	dfs(root)
}