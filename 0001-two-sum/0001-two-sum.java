class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] ans = new int[2];
        int l = 0, r = nums.length-1;
        while(l<r) {
            int sum = nums[l] + nums[r];
            if(sum==target) {
                ans[0] = l;
                ans[1] = r;
                return ans;
            }
            else if(sum!=target && l!=r-1) {
                r--;
            }
            else {
                l++;
                r = nums.length-1;
            }
        }
        return ans;
    }
}