class Solution {
    public int climbStairs(int n, int[] costs) {
        int[] dp = new int[n+1];
        
        for(int i=1; i<=n; i++) {
            int j1 = dp[i-1] + 1;
            int j2 = i-2>=0 ? dp[i-2] + 4 : Integer.MAX_VALUE;
            int j3 = i-3>=0 ? dp[i-3] + 9 : Integer.MAX_VALUE;
            int minPrevCost = Math.min(j1, Math.min(j2, j3));
            dp[i] = minPrevCost + costs[i-1];
        }
        return dp[n];
    }
}