class Solution {
public:

    bool solve(int i, int j, bool turn, int a, int b, vector<int> &piles, int dp[504][504]) {
        if(i==j) {
            if(turn)
                a+=piles[i];
            else
                b+=piles[i];
            if(a>b)
                return true;
            return false;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        bool pickEnd, pickStart;
        if(turn) {
            a+=piles[j];
            pickEnd = solve(i, j-1, !turn, a, b, piles, dp);
            a-=piles[j];
            a+=piles[i];
            pickStart = solve(i+1, j, !turn, a, b, piles, dp);
            return dp[i][j] = pickStart || pickEnd;
        }
        else {
            b+=piles[j];
            pickEnd = solve(i, j-1, !turn, a, b, piles, dp);
            b-=piles[j];
            b+=piles[i];
            pickStart = solve(i+1, j, !turn, a, b, piles, dp);
            return dp[i][j] = pickStart || pickEnd;
        }
    }

    bool stoneGame(vector<int>& piles) {
        int dp[504][504];
        memset(dp, -1, sizeof(dp));
        return solve(0, piles.size()-1, true, 0, 0, piles, dp);
    }
};