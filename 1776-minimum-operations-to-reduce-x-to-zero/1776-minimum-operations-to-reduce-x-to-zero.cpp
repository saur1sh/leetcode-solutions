class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int tar=0, n=nums.size();
        for(const int &e: nums)
            tar+=e;
        tar -= x;
        if(tar==0)
            return n;
        int l=0, curr=0, maxLen=0;
        for(int r=0; r<nums.size(); r++) {
            curr+=nums[r];
            while(l<=r && curr>tar) {
                curr-=nums[l++];
            }
            if(tar==curr)
                maxLen = max(maxLen, r-l+1);
        }
        return maxLen ? n-maxLen : -1;
    }
};