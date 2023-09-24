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

	int visit(TreeNode* root, int &cams) {
		if (!root)
			return 1;
		if (root->left == NULL && root->right == NULL)
			return -1;
		int left = visit(root->left, cams);
		int right = visit(root->right, cams);
		if (left == -1 && right == -1) {
			cams++;
			return 0;
		}
		else if ((left == 0 && right==1) || (right == 0 && left==1) || (left==0 && right==0)) {
			return 1;
		}
		else if (left == 1 && right == 1) {
			return -1;
		}
    else {
      cams++;
      return 0;
    }
	}

	int minCameraCover(TreeNode* root) {
		int cams = 0;
		return (visit(root, cams)<0 ? 1 : 0) + cams;
	}
};