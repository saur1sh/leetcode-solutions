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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root)
            return ans;
        int curr = 1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int nextLevel = 0;
            while(curr--) {
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left) {
                    q.push(temp->left);
                    nextLevel++;
                }
                if(temp->right) {
                    q.push(temp->right);
                    nextLevel++;
                }
                if(curr==0) {
                    ans.push_back(temp->val);
                }
            }
            curr = nextLevel;
        }
        return ans;
    }
};