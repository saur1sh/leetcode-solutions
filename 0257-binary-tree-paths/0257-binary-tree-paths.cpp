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

    void solve(TreeNode* root, string t, vector<string> &ans) {
        t += to_string(root->val);
        bool leaf = true;
        if(root->left) {
            t += "->";
            leaf = false;
            solve(root->left, t, ans);
        }
        if(root->right) {
            if(leaf) {
                t += "->";
                leaf = false;
            }
            solve(root->right, t, ans);
        }
        if(leaf) {
            ans.push_back(t);
        }
        return;
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        solve(root, "", ans);
        return ans;
    }
};