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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        queue<TreeNode*> q;
        int curr=1;
        q.push(root);
        while(!q.empty()) {
            vector<int> level;
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
                level.push_back(temp->val);
            }
            curr = nextLevel;
            ans.push_back(level);
        }
        return ans;
    }
};