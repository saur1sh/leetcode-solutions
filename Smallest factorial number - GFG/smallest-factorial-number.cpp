//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    
        int occurences(int x) {
            int count=0;
            int di = 5;
            while(true) {
                int val = floor(x/di);
                if(val>0) {
                    count+=val;
                    di*=5;
                }
                else return count;
            }
        }
        
        int findNum(int n)
        {
            int x = 5*n;
            int prev = x;
            int count = occurences(x);
            while(count>=n) {
                prev = x;
                x--;
                count = occurences(x);
            }
            return prev;
        }
};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}
// } Driver Code Ends