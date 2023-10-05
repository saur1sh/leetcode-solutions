class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l=-1, maxi=0;
        for(int r=0; r<nums.size(); r++) {
            if(nums[r]==1)
                maxi = max(maxi, r-l);
            else
                l = r;
        }
        return maxi;
    }
};