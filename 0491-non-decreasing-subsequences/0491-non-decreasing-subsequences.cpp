class Solution {
public:

    void solve(int i, vector<int> &nums, vector<int> temp, set<vector<int>> &ans) {
        if(i==nums.size()) {
            if(temp.size()>1)
                ans.insert(temp);
            return;
        }
        if(temp.size()==0 || temp.back()<=nums[i]) {
            temp.push_back(nums[i]);
            solve(i+1, nums, temp, ans);
            temp.pop_back();
        }
        solve(i+1, nums, temp, ans);
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> temp;
        vector<vector<int>> res;
        solve(0, nums, temp, ans);
        for(auto x: ans) {
            res.push_back(x);
        }
        return res;
    }
};