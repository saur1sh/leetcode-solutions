class Solution:

    def solve(self, i, j, m, n, dp):
        if(i>=m or j>=n):
            return 0
        if(i==m-1 and j==n-1):
            return 1
        if(dp[i][j]!=-1):
            return dp[i][j]
        right = self.solve(i, j+1, m, n, dp)
        down = self.solve(i+1, j, m, n, dp)
        dp[i][j] = right+down
        return dp[i][j]

    def uniquePaths(self, m: int, n: int) -> int:
        dp = [[-1 for _ in range(n+1)] for _ in range(m+1)]
        return self.solve(0, 0, m, n, dp)