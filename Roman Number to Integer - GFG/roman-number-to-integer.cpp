//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &s) {
        int x=0;
        
        map <char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        if(s.length()==1) return mp[s[0]];
        int i=s.length();
        while(i>=0) {
            if(i==0) {
                x += mp[s[0]];
                break;
            }
            if(mp[s[i-1]]<mp[s[i]]){
                x += (mp[s[i]]-mp[s[i-1]]);
                i -= 2;
            }
            else {
                x += mp[s[i]];
                i--;
            }
        }
        return x;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends