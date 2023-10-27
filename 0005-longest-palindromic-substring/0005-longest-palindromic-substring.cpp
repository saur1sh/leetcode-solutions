class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int dp[1000][1000];
        int ans[2] = {1, 0};
        for(int g=0; g<n; g++) {
            for(int i=0, j=g; j<n; i++, j++) {
                if(g==0) dp[i][j] = 1;
                else if(g==1) {
                    if(s[i]==s[j]) dp[i][j] = 2;
                    else dp[i][j] = 0;
                }
                else {
                    if(s[i]==s[j] && dp[i+1][j-1]) 
                        dp[i][j] = 1 + g;
                    else dp[i][j] = 0;
                }
                if(dp[i][j]>ans[0]) {
                    ans[0] = dp[i][j];
                    ans[1] = i;
                }
            }
        }
        string temp = s.substr(ans[1], ans[0]);
        return temp;
    }
};