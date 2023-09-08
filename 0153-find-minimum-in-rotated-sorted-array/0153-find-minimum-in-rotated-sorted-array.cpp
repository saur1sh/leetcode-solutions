class Solution {
public:
    int findMin(vector<int>& arr) {
        int lo=0, hi=arr.size()-1;
        int mini=INT_MAX;
        int mid;
        while(lo<=hi) {
            mid = lo + (hi-lo)/2;
            if(arr[lo]<=arr[mid]) {
                mini = min(arr[lo], mini);
                lo = mid+1;
            }
            else {
                mini = min(arr[mid], mini);
                hi = mid-1;
            }
        }
        return mini;
    }
};