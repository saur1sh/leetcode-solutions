//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minimumCostOfBreaking(vector<int> a, vector<int> b, int m, int n){
        m--;
        n--;
        int hor = 1, ver = 1;
    	sort(a.begin(), a.end(), greater<int>());
    	sort(b.begin(), b.end(), greater<int>());
    	int i1 = 0, i2 = 0;
    	int cost = 0;
    	while (i1 < m && i2 < n) {
    		if (a[i1] > b[i2]) {
    			cost += a[i1] * hor;
    			i1++;
    			ver++;
    		}
    		else {
    			cost += ver * b[i2];
    			i2++;
    			hor++;
    		}
    	}
    	while (i1 < m) {
    		cost += a[i1] * hor;
    		i1++;
    	}
    	while (i2 < n) {
    		cost += b[i2] * ver;
    		i2++;
    	}
    	return cost;
    }
};



//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int m, n;
	    cin >> m >> n;
	    vector<int>X(m - 1), Y(n - 1);
	    for(int i = 0; i < m - 1; i++){
	        cin >> X[i];
	    }
	    for(int i = 0; i < n - 1; i++){
	        cin >> Y[i];
	    }
	    Solution ob;
	    int ans = ob.minimumCostOfBreaking(X, Y, m, n);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends