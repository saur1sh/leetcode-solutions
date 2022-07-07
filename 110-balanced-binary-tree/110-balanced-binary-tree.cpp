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
    bool val=true;
    int height(TreeNode* root, int& diff) {
        if(!root)
            return 0;
        int lh = height(root->left, diff);
        int rh = height(root->right, diff);
        diff = abs(lh-rh);
        if(diff>1)
            val = false;
        return max(1+lh, 1+rh);
    }
    
    bool isBalanced(TreeNode* root) {
        int diff = 0;
        height(root, diff);
        if(val)
            return true;
        else
            return false;
    }
};