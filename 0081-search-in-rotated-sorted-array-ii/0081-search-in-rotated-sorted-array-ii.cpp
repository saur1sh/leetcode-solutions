class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int lo = 0, hi = arr.size()-1;
        while(lo<=hi) {
            int mid = lo + (hi-lo)/2;
            if(arr[mid]==target) {
                return true;
            }
            if(arr[lo]==arr[mid] && arr[mid]==arr[hi]) {
                lo++;
                hi--;
                continue;
            }
            if(arr[lo]<=arr[mid]) {
                if(target<=arr[mid] && target>=arr[lo]) {
                    hi = mid-1;
                }
                else
                    lo = mid+1;
            }
            else {
                if(target>=arr[mid] && target<=arr[hi]) {
                    lo = mid+1;
                }
                else
                    hi = mid-1;
            }
        }
        return false;
    }
};