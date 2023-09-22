class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        if s=="":
            return True
        dp = [[0 for _ in range(len(s)+1)] for _ in range(len(t)+1)]
        for i in range(len(t)+1):
            for j in range(len(s)+1):
                if i==0 or j==0:
                    continue
                if t[i-1]==s[j-1]:
                    dp[i][j]=1+dp[i-1][j-1]
                    if dp[i][j]==len(s):
                        return True
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        return False