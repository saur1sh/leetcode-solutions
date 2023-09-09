class Solution {
public:

    int dp[1000];

    int solve(int tar, vector<int> &nums) {
        if(tar==0) {
            return 1;
        }
        else if(tar<0) {
            return 0;
        }
        if(dp[tar]!=-1)
            return dp[tar];
        int combs = 0;
        for(int i=0; i<nums.size(); i++) {
            int res = solve(tar-nums[i], nums);
            if(res>0) {
                combs+=res;
            }
        }
        return dp[tar] = combs;
    }

    int combinationSum4(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
        return solve(target, nums);
    }
};