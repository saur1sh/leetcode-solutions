class Solution {
public:

    int minimumEffortPath(vector<vector<int>>& ht) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int n = ht.size(), m = ht[0].size();
        int dr[4] = { -1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        pq.push({0, {0, 0}});
        int dist[101][101];
        memset(dist, 9999999, sizeof(dist));
        dist[0][0] = 0;
        while (!pq.empty()) {
            auto a = pq.top();
            int di = a.first;
            int u = a.second.first;
            int v = a.second.second;
            pq.pop();
            if(di>dist[u][v]) continue;
            if (u == n-1 && v == m-1) {
                return di;
            }
            for (int i = 0; i < 4; i++) {
                int r = u + dr[i];
                int c = v + dc[i];
                if (r < n && c < m && r >= 0 && c >= 0) {
                    int maxDiff = max(abs(ht[u][v] - ht[r][c]), di);
                    if(maxDiff<dist[r][c]) {
                        pq.push({maxDiff, {r, c}});
                        dist[r][c] = maxDiff;
                    }
                }
            }
        }
        return -1;
    }
};