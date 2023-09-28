class Solution {
public:

    void solve(vector<int> temp, int vis[], vector<int> &nums, vector<vector<int>> &ans) {
        if(temp.size()==nums.size()) {
            ans.push_back(temp);
            return;
        }
        for(int i=0; i<nums.size(); i++) {
            if(!vis[i]) {
                temp.push_back(nums[i]);
                vis[i] = 1;
                solve(temp, vis, nums, ans);
                temp.pop_back();
                vis[i] = 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int vis[7] = {};
        solve({}, vis, nums, ans);
        return ans;
    }
};