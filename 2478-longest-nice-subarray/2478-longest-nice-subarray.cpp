class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int curr = 0;
        int l=0, r=0, maxi = 0;
        while(r<nums.size()) {
            if((nums[r]&curr)==0) {
                maxi = max(maxi, r-l+1);
                curr ^= nums[r];
                r++;
            }
            else {
                curr ^= nums[l];
                l++;
            }
        }
        return maxi;
    }
};