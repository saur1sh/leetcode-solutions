class Solution {
public:
        int n, m;
        int MOD = 1e9 + 7;
        vector<vector<vector<int>>> dp;
        int helper(int idx, int maxSoFar, int remain) {
            if (idx == n) {
                if (remain == 0) {
                    return 1;
                }
                return 0;
            }
            if (remain < 0) {
                return 0;
            }

            if (dp[idx][maxSoFar][remain] != -1) {
                return dp[idx][maxSoFar][remain];
            }

            int ans = 0;
            // repititions of elements is allowed, hence we need to add the possible arrays with repititions as well
            for (int num=1;num<=maxSoFar;num++) {
                ans = (ans + helper(idx + 1, maxSoFar, remain))%MOD;
            }

            for (int num = maxSoFar+1;num<=m;num++) {
                ans = (ans + helper(idx + 1, num, remain-1))%MOD;
            }

            dp[idx][maxSoFar][remain] = ans;
            return ans;
        }

        int numOfArrays(int n, int m, int k) {
            dp = vector(n, vector(m + 1, vector(k+1, -1)));
            this->n = n;
            this->m = m;
            return helper(0, 0, k);
        }
};