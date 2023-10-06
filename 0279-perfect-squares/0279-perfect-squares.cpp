class Solution {
public:
    int numSquares(int n) {
        int dp[10002];
        dp[0] = 0;
        dp[1] = 1;
        for(int i=2; i<=n; i++) {
            int mini = INT_MAX;
            for(int j=1; j*j<=n; j++) {
                int val = i - j*j;
                if(val>=0 && dp[val]<mini) {
                    mini = dp[val];
                }
            }
            dp[i] = mini+1;
        }
        return dp[n];
    }
};