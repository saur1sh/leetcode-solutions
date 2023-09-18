class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m=mat[0].size();
        priority_queue<pair<int, int>, vector<pair<int, int>> > pq;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j]==0 ) {
                    pq.push({j, i});
                    if(pq.size()>k)
                        pq.pop();
                    break;
                }
            }
            if(mat[i][m-1]==1) {
                pq.push({m, i});
                if(pq.size()>k)
                    pq.pop();
            }
        }
        vector<int> ans;
        while(pq.size()!=0) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};