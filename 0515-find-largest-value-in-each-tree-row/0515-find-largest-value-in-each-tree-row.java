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
    public List<Integer> largestValues(TreeNode root) {
        List<Integer> ans = new ArrayList<Integer>();
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        if(root==null)
            return ans;
        q.add(root);
        while(!q.isEmpty()) {
            int i = q.size();
            int maxi = Integer.MIN_VALUE;
            while(i--!=0) {
                TreeNode temp = q.poll();
                maxi = Integer.max(temp.val, maxi);
                if(temp.left!=null) {
                    q.add(temp.left);
                }
                if(temp.right!=null) {
                    q.add(temp.right);
                }
            }
            ans.add(maxi);
        }
        return ans;
    }
}