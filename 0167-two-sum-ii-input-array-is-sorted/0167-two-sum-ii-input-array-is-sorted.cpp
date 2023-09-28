class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int lo=0, hi=nums.size()-1;
        while(lo<hi) {
            int sum = nums[lo]+nums[hi];
            if(sum==target)
                return {lo+1, hi+1};
            else if(sum<target) {
                lo++;
            }
            else {
                hi--;
            }
        }
        return {-1, -1};
    }
};