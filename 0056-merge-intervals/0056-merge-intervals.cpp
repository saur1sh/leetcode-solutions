class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        sort(a.begin(), a.end());
        vector<vector<int>> ans;
        for(auto &e: a) {
            if(ans.size()==0 || ans.back()[1]<e[0])
                ans.push_back(e);
            else
                ans.back()[1] = max(ans.back()[1], e[1]);
        }
        return ans;
    }
};