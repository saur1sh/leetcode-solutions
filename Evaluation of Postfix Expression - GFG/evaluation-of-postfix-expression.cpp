//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
    bool isOperator(char x) {
        if(x=='+' || x=='-' || x=='/' || x=='*') return true;
        return false;
    }
    
    int solve(int x, int y, char op) {
        if(op=='-') return x-y;
        else if(op=='+') return x+y;
        else if(op=='/') return x/y;
        else return x*y;
    }
    
    int evaluatePostfix(string S)
    {
        stack<int> st;
        for(int i=0; i<S.length(); i++) {
            char c = (char)S[i];
            if(isOperator(c)) {
                int x1 = st.top();
                st.pop();
                int x2 = st.top();
                st.pop();
                int ans = solve(x2, x1, c);
                st.push(ans);
            }
            else {
                int x = (int)(S[i])-48;
                st.push(x);
            }
        }
        return st.top();
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends