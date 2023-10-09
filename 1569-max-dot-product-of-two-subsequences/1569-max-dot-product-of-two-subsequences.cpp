class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int dp[501][501];
        dp[0][0] = nums1[0]*nums2[0];
        int n = nums2.size(), m = nums1.size();
        for(int i=1; i<n; i++) {
            dp[0][i] = max(dp[0][i-1], nums1[0]*nums2[i]);
        }
        for(int i=1; i<m; i++) {
            dp[i][0] = max(dp[i-1][0], nums1[i]*nums2[0]);
        }
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                int dot = max(dp[i-1][j-1] + nums1[i]*nums2[j], nums1[i]*nums2[j]);
                dp[i][j] = max(dot, max(dp[i-1][j], dp[i][j-1]));
            }
        }
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp[m-1][n-1];
    }
};