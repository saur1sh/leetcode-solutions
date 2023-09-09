class Solution {
public:

    int solve(int ind, int tar, vector<int> &nums, int dp[202][1001]) {
        if(tar==0) {
            return 1;
        }
        else if(tar<0) {
            return 0;
        }
        if(dp[ind][tar]!=-1)
            return dp[ind][tar];
        int combs = 0;
        for(int i=0; i<nums.size(); i++) {
            int res = solve(i, tar-nums[i], nums, dp);
            if(res>0) {
                combs+=res;
            }
        }
        return dp[ind][tar] = combs;
    }

    int combinationSum4(vector<int>& nums, int target) {
        int dp[202][1001];
        memset(dp, -1, sizeof(dp));
        return solve(0, target, nums, dp);
    }
};