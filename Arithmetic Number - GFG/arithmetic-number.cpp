//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int inSequence(int A, int B, int C){
        double x = (double)(B-A)/C;
        if(C==0) {
            if(A==B) return true;
            else return false;
        }
        if(ceil(x)==floor(x) && x>=0) return true;
        return false;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int A, B, C;
        cin>>A>>B>>C;
        
        Solution ob;
        cout<<ob.inSequence(A, B, C)<<endl;
    }
    return 0;
}
// } Driver Code Ends