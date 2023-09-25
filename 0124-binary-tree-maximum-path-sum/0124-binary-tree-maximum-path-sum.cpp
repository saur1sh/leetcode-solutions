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

    int solve(TreeNode* root, int curr, int &maxi) {
        if(!root) {
            return 0;
        }
        int left = solve(root->left, curr, maxi);
        int right = solve(root->right, curr, maxi);
        curr = root->val;
        if(left>0) {
            curr += left;
        }
        if(right>0) {
            curr += right;
        }
        maxi = max(curr, maxi);
        curr = root->val;
        if(left>=0 && right>0) {
            curr += (left>right) ? left : right;
        }
        else if(left<=0 && right>=0) {
            curr += right;
        }
        else if(left>=0 && right<=0) {
            curr += left;
        }
        cout<<curr<<endl;
        return (curr<0) ? 0 : curr;
    }

    int maxPathSum(TreeNode* root) {
        int maxi =INT_MIN;
        solve(root, 0, maxi);
        return maxi;
    }
};