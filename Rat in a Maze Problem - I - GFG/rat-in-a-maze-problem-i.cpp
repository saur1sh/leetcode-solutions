//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
	void ratMaze(int i, int j, vector<vector<int>> &m, vector<vector<int>> &vis, string move, vector<string> &ans, int n) {

		if (i == n - 1 && j == n - 1) {
			ans.push_back(move);
			return;
		}
        
        // Up
		if (i - 1 >= 0 && vis[i - 1][j]==0 && m[i - 1][j] == 1) {
			vis[i][j] = 1;
			ratMaze(i - 1, j, m, vis, move + 'U', ans, n);
			vis[i][j] = 0;
		}
        
		// Down
		if (i + 1 < n && vis[i + 1][j]==0 && m[i + 1][j] == 1) {
			vis[i][j] = 1;
			ratMaze(i + 1, j, m, vis, move + 'D', ans, n);
			vis[i][j] = 0;
		}

		// Left
		if (j - 1 >= 0 && vis[i][j - 1]==0 && m[i][j - 1] == 1) {
			vis[i][j] = 1;
			ratMaze(i, j - 1, m, vis, move + 'L', ans, n);
			vis[i][j] = 0;
		}

		// Right
		if (j + 1 < n && vis[i][j + 1]==0 && m[i][j + 1] == 1) {
			vis[i][j] = 1;
			ratMaze(i, j + 1, m, vis, move + 'R', ans, n);
			vis[i][j] = 0;
		}

		
	}

	vector<string> findPath(vector<vector<int>> &m, int n) {
		vector<string> ans;
		vector<vector<int>> vis(n, vector<int> (n, 0));
		if (m[0][0] == 1) ratMaze(0, 0, m, vis, "", ans, n);
		return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends