class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        int n=coins.size();
        int dp[10001] = {0};
        dp[0] = 1;
        for(auto &e: coins) {
            for(int amt=e; amt<amount+1; amt++) {
                int tar = amt-e;
                if(tar==0) dp[amt] = 1;
                else if(dp[tar] && dp[amt]==0)
                    dp[amt] = 1 + dp[tar];
                else if(dp[tar]) dp[amt] = min(1+dp[tar], dp[amt]);
            }
        }
        if(dp[amount]==0) return -1;
        return dp[amount];
    }
};