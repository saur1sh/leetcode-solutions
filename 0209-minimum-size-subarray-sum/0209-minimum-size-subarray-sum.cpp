class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0, ans=0, sum=0;
        for(int r=0; r<nums.size(); r++) {
            sum+=nums[r];
            while(sum>=target) {
                if(ans>r-l+1 || ans==0) {
                    ans = r-l+1;
                }
                sum-=nums[l++];
            }
        }
        return ans;
    }
};