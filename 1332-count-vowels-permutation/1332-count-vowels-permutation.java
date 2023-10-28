class Solution {
    public int countVowelPermutation(int n) {
        long[][] dp = new long[n][5];
        for(int i=0; i<5; i++) {
            dp[0][i] = 1;
        }
        int mod = 1000000000+7;
        for(int i=1; i<n; i++) {
            dp[i][0] = dp[i-1][1];
            dp[i][1] = (dp[i-1][0]%mod + dp[i-1][2]%mod)%mod;
            dp[i][2] = (dp[i-1][0]%mod + dp[i-1][1]%mod + dp[i-1][3]%mod + dp[i-1][4]%mod)%mod;
            dp[i][3] = (dp[i-1][2]%mod + dp[i-1][4]%mod)%mod;
            dp[i][4] = dp[i-1][0];
        }
        long ans = 0;
        for(int i=0; i<5; i++) {
            ans = (ans%mod + dp[n-1][i]%mod)%mod;
        }
        return (int)ans;
    }
}