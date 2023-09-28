class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int> (n));
        int visits = 1;
        int i=0, j=0, dir=1;
        bool vis[n][n];
        memset(vis, false, sizeof(vis));
        while(visits<=n*n) {
            if(dir==1) {
                ans[i][j] = visits;
                vis[i][j] = true;
                if(j+1<n && !vis[i][j+1]) {
                    j++;
                }
                else {
                    i++;
                    dir=2;
                }
            }
            else if(dir==2) {
                ans[i][j] = visits;
                vis[i][j] = true;
                if(i+1<n && !vis[i+1][j]) {
                    i++;
                }
                else {
                    j--;
                    dir=3;
                }
            }
            else if(dir==3) {
                ans[i][j] = visits;
                vis[i][j] = true;
                if(j-1>=0 && !vis[i][j-1]) {
                    j--;
                }
                else {
                    i--;
                    dir=4;
                }
            }
            else {
                ans[i][j] = visits;
                vis[i][j] = true;
                if(i-1>=0 && !vis[i-1][j]) {
                    i--;
                }
                else {
                    j++;
                    dir=1;
                }
            }
            visits++;
        }
        return ans;
    }
};