class Solution {
    public int longestNiceSubarray(int[] nums) {
        int curr = 0;
        int maxi = 0;
        int l = 0, r = 0;
        while (r<nums.length) {
            if ((curr&nums[r])==0) {
                curr ^= nums[r];
                maxi = Math.max(maxi, r-l+1);
                r++;
            }
            else {
                curr ^= nums[l];
                l++;
            }
        }
        return maxi;
    }
}