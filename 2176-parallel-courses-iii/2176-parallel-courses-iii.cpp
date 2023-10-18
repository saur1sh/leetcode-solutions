class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& rel, vector<int>& time) {
        vector<int> adj[n+1];
        vector<int> ind(n+1, 0);
        for(const auto &e: rel) {
            adj[e[0]].push_back(e[1]);
            ind[e[1]]++;
        }
        int maxi = 0;
        vector<int> vis(n+1);
        queue<pair<int, int>> q;
        for(int i=0; i<n+1; i++) {
            if(i!=0 && ind[i]==0)
                q.push({i, time[i-1]});
        }
        while(!q.empty()) {
            int u = q.front().first;
            int cst = q.front().second;
            q.pop();
            for(const auto &v: adj[u]) {
                vis[v] = max(vis[v], cst);
                if(--ind[v]==0)
                    q.push({v, vis[v]+time[v-1]});
            }
            maxi = (cst>maxi) ? cst : maxi ;
        }
        return maxi;
    }
};