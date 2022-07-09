class Solution {
public:
    int rob(vector<int>& nums) {
		int n = nums.size();
		if (n == 1)
			return nums[0];
		return max(robs(nums, 1, n), robs(nums, 0, n - 1));
	}

	int robs(vector<int>& nums, int st, int n) {
		int temp, rob1 = 0, rob2 = 0;
		for (int i = st; i < n; i++) {
			temp = max(rob1 + nums[i], rob2);
			rob1 = rob2;
			rob2 = temp;
		}
		return rob2;
	}
};