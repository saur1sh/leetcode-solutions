bool cmp (vector<int> &a, vector<int> &b) {
    return a[1]<b[1];
}

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), cmp);
        int cnt=0, prev=INT_MIN;
        for(const auto &e: pairs) {
            if(e[0]>prev) {
                cnt++;
                prev = e[1];
            }
        }
        return cnt;
    }
};