/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int minDepth(TreeNode root) {
        if (root == null)
            return 0;
        return 1 + helper(root);
    }

    private int helper(TreeNode root) {
        if (root.left == null && root.right == null)
            return 0;
        int left = root.left != null ? helper(root.left) + 1 : Integer.MAX_VALUE;
        int right = root.right != null ? helper(root.right) + 1 : Integer.MAX_VALUE;
        return Math.min(left, right);
    }
}