class Solution {
public:

    int combinationSum4(vector<int>& nums, int target) {
        unsigned int dp[1001];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(int i=1; i<=target; i++) {
            for(const auto &e: nums) {
                if(i-e>=0) {
                    dp[i] += dp[i-e];
                }
            }
        }
        return dp[target];
    }
};