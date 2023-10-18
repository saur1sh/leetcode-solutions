class Solution {
public:

    void solve(int ind, int left, vector<int> temp, vector<int> &cand, vector<vector<int>> &ans) {
        if(left==0) {
            ans.push_back(temp);
            return;
        }
        for(int i=ind; i<cand.size(); i++) {
            if(i>ind && cand[i]==cand[i-1])
                continue;
            if(cand[i]>left)
                break;
            temp.push_back(cand[i]);
            solve(i+1, left-cand[i], temp, cand, ans);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        solve(0, target, {}, candidates, ans);
        return ans;
    }
};