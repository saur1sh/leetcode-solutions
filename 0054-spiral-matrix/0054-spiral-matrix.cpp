class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int visits = 0;
        int i=0, j=0, dir=1;
        vector<int> ans;
        bool vis[11][11];
        memset(vis, false, sizeof(vis));
        while(visits<n*m) {
            if(dir==1) {
                ans.push_back(mat[i][j]);
                vis[i][j] = true;
                if(j+1<m && !vis[i][j+1]) {
                    j++;
                }
                else {
                    i++;
                    dir=2;
                }
            }
            else if(dir==2) {
                ans.push_back(mat[i][j]);
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
                ans.push_back(mat[i][j]);
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
                ans.push_back(mat[i][j]);
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