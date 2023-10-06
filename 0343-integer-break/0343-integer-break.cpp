class Solution {
public:

    int solve(int n, int dp[59]) {
        if(dp[n]!=-1)
            return dp[n];
        int ans = n;
        for(int i=1; i<n; i++) {
            int mul = solve(i, dp) * solve(n-i, dp);
            ans = (mul>ans) ? mul : ans;
        }
        return dp[n] = ans;
    }

    int integerBreak(int n) {
        if(n==1 || n==2)
            return 1;
        if(n==3)
            return 2;
        int dp[59];
        memset(dp, -1, sizeof(dp));
        return solve(n, dp);
    }
};