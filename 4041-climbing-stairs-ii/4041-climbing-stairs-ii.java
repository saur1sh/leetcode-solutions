class Solution {
    public int climbStairs(int n, int[] costs) {
        return minJumps(n, costs, new int[n+1]);
    }

    private int minJumps(int n, int[] costs, int[] dp) {
        if(n==0) {
            return 0;
        }
        if(dp[n]!=0) {
            return dp[n];
        }
        int j1 = minJumps(n-1, costs, dp) + costs[n-1] + 1;
        int j2 = n-2>=0 ? minJumps(n-2, costs, dp) + costs[n-1] + 4 : Integer.MAX_VALUE;
        int j3 = n-3>=0 ? minJumps(n-3, costs, dp) + costs[n-1] + 9 : Integer.MAX_VALUE;
        dp[n] = Math.min(j1, Math.min(j2, j3));
        return dp[n];
    }
}