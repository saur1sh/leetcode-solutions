class Solution {
    public int coinChange(int[] coins, int amount) {
        if (amount == 0)
            return 0;
        int[] dp = new int[10001];
        dp[0] = 1;
        for (int e : coins) {
            for (int curr = e; curr < amount + 1; curr++) {
                int tar = curr - e;
                if (tar == 0) {
                    dp[curr] = 1;
                } else if (dp[tar] != 0) {
                    if (dp[curr] == 0) {
                        dp[curr] = 1 + dp[tar];
                    } else {
                        dp[curr] = Math.min(1 + dp[tar], dp[curr]);
                    }
                }
            }
        }
        return dp[amount] == 0 ? -1 : dp[amount];
    }
}