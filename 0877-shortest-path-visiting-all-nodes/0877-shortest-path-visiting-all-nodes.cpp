class Solution {
    struct states {
        int mask, node, dist;
    };

public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int fina = (1<<n)-1;
        queue<states> q;
        unordered_set<int> vis;
        for(int i=0; i<n; i++) {
            q.push({1<<i, i, 0});
            vis.insert((1<<i)*16+i);
        }
        while(!q.empty()) {
            states curr = q.front();
            q.pop();
            if(curr.mask==fina) {
                return curr.dist;
            }
            for(const int &e: graph[curr.node]){
                int newMask = curr.mask | (1<<e);
                int hashVal = newMask*16+e;
                if(vis.find(hashVal)==vis.end()) {
                    q.push({newMask, e, curr.dist+1});
                    vis.insert(hashVal);
                }
            }
        }
        return -1;
    }
};