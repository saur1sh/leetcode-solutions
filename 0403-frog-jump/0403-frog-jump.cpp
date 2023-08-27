class Solution {
public:

    map<pair<int, int>, bool> mp;

    bool solve(int ind, int k, vector<int> &st) {
        if(ind==st.size()-1) {
            return true;
        }
        if(ind>=st.size())
            return false;
        if(mp.find({ind, k})!=mp.end())
            return mp[{ind, k}];
        int canJump[3];
        memset(canJump, -1, sizeof(canJump));
        int sizes[3] = {k-1, k, k+1};
        for(int i=ind+1; i<st.size(); i++) {
            int diff = st[i]-st[ind];
            if(diff>k+1)
                break;
            if(diff==k-1){
                canJump[0] = i;
            }
            else if(diff==k){
                canJump[1] = i;
            }
            else if(diff==k+1){
                canJump[2] = i;
            }
        }
        for(int i=0; i<3; i++) {
            if(canJump[i]!=-1) {
                if(solve(canJump[i], sizes[i], st)){
                    return mp[{ind, k}] = true;
                }
            }
        }
        return mp[{ind, k}] = false;
    }

    bool canCross(vector<int>& stones) {
        if(stones[1]>1)
            return false;
        return solve(1, 1, stones);
    }
};