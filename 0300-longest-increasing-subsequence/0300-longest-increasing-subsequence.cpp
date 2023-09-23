class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int dp[2501];
        dp[0] = 1;
        int ans = 1;
        for(int i=1; i<nums.size(); i++) {
            int maxi = -1;
            for(int j=0; j<i; j++) {
                if(nums[j]<nums[i]) {
                  maxi = max(maxi, dp[j]);
                }
            }
            if(maxi==-1)
                dp[i] = 1;
            else
                dp[i] = 1 + maxi;
            ans = max(dp[i], ans);
        }
        for(int i=0; i<nums.size(); i++) {
          cout<<dp[i]<<" ";
        }
        return ans;
    }
};