/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* temp;

public:
    void flatten(TreeNode* root) {
        if (root == NULL)
            return;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        if (temp != NULL) {
            temp->right = root;
        }
        root->left = NULL;
        temp = root;
        flatten(left);
        flatten(right);
    }
};