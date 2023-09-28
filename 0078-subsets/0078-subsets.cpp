class Solution {
public:

    void solve(int ind, vector<int> temp, vector<int> &nums, vector<vector<int>> &ans) {
        if(ind==nums.size()) {
            ans.push_back(temp);
            return;
        }
        solve(ind+1, temp, nums, ans);
        temp.push_back(nums[ind]);
        solve(ind+1, temp, nums, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(0, {}, nums, ans);
        return ans;
    }
};