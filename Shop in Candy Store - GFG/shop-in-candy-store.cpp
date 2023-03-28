//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int n, int k)
    {
        sort(candies, candies+n);
        int total = 0;
        int cost = 0;
        int bought = 0;
        int l = 0, r= n-1;
        vector<int> ans;
        while(total<n) {
            total++;
            bought++;
            cost+=candies[l];
            l++;
            int counts = 0;
            while(l-1<r && counts<k) {
                total++;
                r--;
                counts++;
            }
        }
        ans.push_back(cost);
        total=0, cost = 0, bought = 0;
        l=0, r=n-1;
        while(total<n) {
            total++;
            bought++;
            cost+=candies[r];
            r--;
            int counts = 0;
            while(l-1<r && counts<k) {
                total++;
                l++;
                counts++;
            }
        }
        ans.push_back(cost);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends