/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int remove(TreeNode* root) {
        if(!root)
            return 0;
        int left = remove(root->left);
        int right = remove(root->right);
        if(left==0) {
            root->left = NULL;
        }
        if(right==0) {
            root->right = NULL;
        }
        if(root->val==1 || left==1 || right==1)
            return 1;
        return 0;
    }

    TreeNode* pruneTree(TreeNode* root) {
        return (remove(root)==0) ? NULL : root ;
    }
};