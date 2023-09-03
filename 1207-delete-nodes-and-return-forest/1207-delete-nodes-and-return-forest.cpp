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

    unordered_set<int> mp;

    vector<TreeNode*> deleteNodes(TreeNode* root) {
        queue<pair<TreeNode*, TreeNode*>> q;
        vector<TreeNode*> ans;
        if(mp.find(root->val)==mp.end())
            ans.push_back(root);
        q.push({root, NULL});
        TreeNode* curr;
        TreeNode* currParent;
        while(!q.empty()) {
            curr = q.front().first;
            currParent = q.front().second;
            q.pop();
            int childs=0;
            if(mp.find(curr->val)!=mp.end()) {
                if(curr->left) {
                    vector<TreeNode*> temp1 = deleteNodes(curr->left);
                    for(const auto &e: temp1) {
                        ans.push_back(e);
                    }
                }
                if(curr->right) {
                    vector<TreeNode*> temp2 = deleteNodes(curr->right);
                    for(const auto &e: temp2) {
                        ans.push_back(e);
                    }
                }
                if(currParent!=NULL && currParent->left==curr) {
                    currParent->left = NULL;
                }
                else if(currParent!=NULL && currParent->right==curr){
                    currParent->right = NULL;
                }
            }
            else {
                if(curr->left) {
                    q.push({curr->left, curr});
                }
                if(curr->right) {
                    q.push({curr->right, curr});
                }
            }
        }
        return ans;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(const int &e: to_delete) {
            mp.insert(e);
        }
        return deleteNodes(root);
    }
};