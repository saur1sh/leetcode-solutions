bool cmp (const vector<int> &a, const vector<int> &b) {
    return a[1]<b[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& itv) {
        if(itv.size()==0)
            return 0;
        sort(itv.begin(), itv.end(), cmp);
        int cnt = -1;
        vector<int> prev = itv[0];
        for(const auto &e: itv) {
            if(prev[1]>e[0]) {
                cnt++;
            }
            else
                prev = e;
        }
        return cnt;
    }
};