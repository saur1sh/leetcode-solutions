class Solution {
    public int change(int amount, int[] coins) {
        int[] dp = new int[5001];
        dp[0] = 1;
        for(int e: coins) {
            for(int amt=e; amt<amount+1; amt++) {
                int tar = amt-e;
                if(dp[tar]!=0) {
                    dp[amt] += dp[tar];
                }
            }
        }
        return dp[amount];
    }
}