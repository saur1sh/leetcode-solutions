class Solution {
public:

    void solve(int open, int closed, int &n, string t, vector<string> &ans) {
        if( open>n || closed>n || closed>open) 
            return;
        if(open==closed && open==n) {
            ans.push_back(t);
            return;
        }
        if(open==closed) {
            t += "(";
            solve(open+1, closed, n, t, ans);
        }
        else {
            t += "(";
            solve(open+1, closed, n, t, ans);
            t.pop_back();
            t += ")";
            solve(open, closed+1, n, t, ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(0, 0, n, "", ans);
        return ans;
    }
};