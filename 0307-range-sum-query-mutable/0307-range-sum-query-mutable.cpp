int speed_up = []{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Node {
public:
	int data, iL, iR;
	Node* left;
	Node* right;

	Node(int iL, int iR): iL(iL), iR(iR) {}

};

Node* constructTree(vector<int> &nums, int l, int r) {
	if (l == r) {
		Node* leaf = new Node(l, r);
		leaf->data = nums[l];
		return leaf;
	}
	int mid = (l + r) / 2;
	Node* node = new Node(l, r);
	node->left = constructTree(nums, l, mid);
	node->right = constructTree(nums, mid + 1, r);
	node->data = node->left->data + node->right->data;
	return node;
}

int query(Node* root, int l, int r) {
	if (root->iL >= l && root->iR <= r) {
		return root->data;
	}
	else if (root->iL > r || root->iR < l) {
		return 0;
	}
	else {
		return (query(root->left, l, r) + query(root->right, l, r));
	}
}

int updateVal(Node* root, int index, int val) {
	if (index >= root->iL && index <= root->iR) {
		if (index == root->iL && index == root->iR) {
			root->data = val;
		}
		else {
			int leftSum = updateVal(root->left, index, val);
			int rightSum = updateVal(root->right, index, val);
			root->data = leftSum + rightSum;
		}
	}
	return root->data;
}

class NumArray {
private:
	Node* root;

public:

	NumArray(vector<int>& nums) {
		root = constructTree(nums, 0, nums.size() - 1);
	}

	void update(int index, int val) {
        updateVal(root, index, val);
	}

	int sumRange(int left, int right) {
		return query(root, left, right);
	}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */