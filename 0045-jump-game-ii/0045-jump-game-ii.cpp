class Solution {
public:
    int jump(vector<int>& arr) {
        int l=0, r=0, res=0, n=arr.size();
        while(r<n-1) {
            int farthest = 0;
            for(int i=l; i<r+1; i++) {
                farthest = max(farthest, i+arr[i]);
            }
            l = r+1;
            r = farthest;
            res+=1;
        }
        return res; 
    }
};