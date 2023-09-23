class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = nums[0];
        int curr = 0;
        for(const int &e: nums) {
          if(curr<0) curr = e;
          else curr += e;
          maxi = max(curr, maxi);
        }
        return maxi;
    }
};