class Solution {
public:

	const int mod = 1e9 + 7;
	int arrLen;

	int solve(int i, int steps, vector<vector<int>> &dp)
	{
		if (steps == 0 && i == 0)
			return 1;
		if (i < 0 || i >= arrLen || steps == 0 || i > steps)
			return 0;
		if (dp[i][steps] != -1)
			return dp[i][steps];
		return dp[i][steps] = ((solve(i + 1, steps - 1, dp) % mod
		                        + solve(i - 1, steps - 1, dp)) % mod
		                        + solve(i, steps - 1, dp)) % mod;
	}

	int numWays(int steps, int arrLen) {
		vector<vector<int>> dp(steps / 2 + 1, vector<int>(steps + 1, -1));
		this->arrLen = arrLen;
		return solve(0, steps, dp);
	}

};