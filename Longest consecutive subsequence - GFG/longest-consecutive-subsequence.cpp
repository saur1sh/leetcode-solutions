//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
        map<int, int> mp;
        for(int i=0; i<n; i++) mp[arr[i]]++;
        int last= mp.begin()->first;
        int maxi=1;
        int curr=1;
        for(auto x: mp) {
            if(last==x.first) continue;
            else {
                if(x.first==last+1) {
                    curr++;
                    maxi = max(maxi, curr);
                    
                }
                else {
                    curr=1;
                }
                last = x.first;
            }
        }
        return maxi;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends