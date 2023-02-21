//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{

public:
    
    bool canPlace(vector<vector<int>> v, int i, int j, int n) {
        bool cond=true;
        for(int k=0; k<n; k++) if(v[k][j] || v[i][k]) cond=false;
        int k=1;
        while(k<n) {
            if(i+k<n){
                if(j+k<n) {
                    if(v[i+k][j+k]) cond = false;
                }
                if(j-k>=0) {
                    if(v[i+k][j-k]) cond = false;
                }
            }
            if(i-k>=0) {
                if(j+k<n) {
                    if(v[i-k][j+k]) cond = false;
                }
                if(j-k>=0) {
                    if(v[i-k][j-k]) cond = false;
                }
            }
            if(!cond) break;
            k++;
        }
        return cond;
    }
    
    void fill(int col, vector<vector<int>> &bd, vector<int> str, vector<vector<int>> &ans, int n) {
        if(col==n) {
            ans.push_back(str);
            return;
        }
        for(int i=0; i<n; i++) {
            if(canPlace(bd, i, col, n)) {
                bd[i][col] = 1;
                str.push_back(i+1);
                fill(col+1, bd, str, ans, n);
                str.pop_back();
                bd[i][col] = 0;
            }
        }
    }
    
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> ans;
        vector<vector<int>> board(n, vector<int> (n, 0));
        vector<int> st;
        fill(0, board, st, ans, n);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends