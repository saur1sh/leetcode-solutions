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
        set <int> st;
        for(int i=0; i<n; i++) st.insert(arr[i]);
        int count=0;
        set <int> seq;
        for(auto x: st) {
            if(st.find(x-1)==st.end()) {
                count++;
                seq.insert(x);
            }
        }
        int maxi=1;
        for(auto x: seq) {
            int curr=1;
            int temp = x+1;
            while(true) {
                if(st.find(temp)!=st.end()) {
                    temp++;
                    curr++;
                }
                else {
                    maxi = max(curr, maxi);
                    break;
                }
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