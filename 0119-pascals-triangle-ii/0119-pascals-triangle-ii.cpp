class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex+1, 1);
        for(int r=1; r<rowIndex; r++) {
            for(int i=r; i>0; i--) {
                ans[i] += ans[i-1];
            }
        }
        return ans;
    }
};