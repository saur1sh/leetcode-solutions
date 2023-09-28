class Solution {
public:

    void solve(vector<int> temp, unordered_set<int> &vis, vector<int> &nums, vector<vector<int>> &ans) {
        if(vis.size()==nums.size()) {
            ans.push_back(temp);
            return;
        }
        for(int i=0; i<nums.size(); i++) {
            if(vis.find(i)==vis.end()) {
                temp.push_back(nums[i]);
                vis.insert(i);
                solve(temp, vis, nums, ans);
                temp.pop_back();
                vis.erase(i);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_set<int> vis;
        solve({}, vis, nums, ans);
        return ans;
    }
};