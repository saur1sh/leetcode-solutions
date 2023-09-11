class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gs) {
        unordered_map<int, vector<int>> mp;
        vector<vector<int>> ans;
        for(int i=0; i<gs.size(); i++) {
            if(mp.find(gs[i])==mp.end() || mp[gs[i]].size()<gs[i]) {
                mp[gs[i]].push_back(i);
            }
            else {
                ans.push_back(mp[gs[i]]);
                mp[gs[i]].clear();
                mp[gs[i]].push_back(i);
            }
        }
        for(const auto & e: mp) {
            ans.push_back(e.second);
        }
        return ans;
    }
};