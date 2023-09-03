class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n=s.length();
        int maxi = n+1;
        int dp[52];
        memset(dp, maxi, sizeof(dp));
        dp[0] = 0;
        set<string> st (dictionary.begin(), dictionary.end());
        for(int i=1; i<=s.length(); i++) {
            dp[i] = dp[i-1] +1;
            for(int l=1; l<=i; l++) {
                if(st.find(s.substr(i-l, l))!=st.end()) {
                    dp[i] = min(dp[i], dp[i-l]);
                }
            }
        }
        return dp[n];
    }
};