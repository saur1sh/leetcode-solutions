class Solution {
    public int climbStairs(int n) {
        return countWays(n, new int[n+1]);
    }

    private int countWays(int n, int[] dp) {
        dp[0] = 1;
        for(int i=1; i<=n; i++) {
            if(i==1) {
                dp[i] = dp[i-1];
            }
            else {
                dp[i] = dp[i-1] + dp[i-2];
            }
        }
        return dp[n];
    }
}