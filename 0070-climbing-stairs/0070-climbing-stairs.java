class Solution {
    public int climbStairs(int n) {
        return countWays(n, new int[n+1]);
    }

    private int countWays(int n, int[] dp) {

        if(n==0 || n==1) {
            return 1;
        }

        if(dp[n]!=0) {
            return dp[n];
        }

        int s1 = countWays(n-1, dp);
        int s2 = countWays(n-2, dp);
        dp[n] = s1+s2;
        return dp[n];
    }
}