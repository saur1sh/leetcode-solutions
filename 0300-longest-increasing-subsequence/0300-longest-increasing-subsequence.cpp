class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int dp[2501] = {};
        int omaxi = 1;
        for(int i=0; i<nums.size(); i++) {
            int maxi = 0;
            for(int j=0; j<i; j++) {
                if(nums[j]<nums[i]) {
                    maxi = max(maxi, dp[j]);
                }
            }
            dp[i] = maxi + 1;
            if(omaxi<dp[i])
                omaxi = dp[i];
        }
        return omaxi;
    }
};