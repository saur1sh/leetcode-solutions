//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

bool comp(const pair<int, int> a,const pair<int, int> b) {
    return (a.first<b.first);
}

class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        int maxi=0;
        vector<pair<int, int>> v;
        for(int i=0; i<n; i++) {
            v.push_back({price[i], i+1});
        }
        sort(v.begin(), v.end(), comp);
        int stocks= 0;
        int nos = 0;
        int i=0;
        while(stocks<=k && i<n) {
            int j=0;
            while(stocks+v[i].first*(j+1)<=k && (j+1)<=v[i].second) j++;
            stocks+=v[i].first*j;
            nos+=j;
            i++;
        }
        return nos;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends