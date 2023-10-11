class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> start, end;
        for(const auto &e: flowers) {
            start.push_back(e[0]);
            end.push_back(e[1]);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        vector<int> ans;
        for(const auto &e: people) {
            int st = upper_bound(start.begin(), start.end(), e)-start.begin();
            int ed = lower_bound(end.begin(), end.end(), e)-end.begin();
            ans.push_back(st-ed);
        }
        return ans;
    }
};