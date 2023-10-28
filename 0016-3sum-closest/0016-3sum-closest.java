class Solution {
    public int threeSumClosest(int[] nums, int tar) {
        Arrays.sort(nums);
        int n=nums.length;
        int mini = Integer.MAX_VALUE;
        int ans = 0;
        boolean turn = true;
        for(int i=0; i<n; i++) {
            int k = n-1;
            for(int j=i+1; j<k;) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum==tar)
                    return tar;
                int diff = Math.abs(sum-tar);
                if(diff<mini) {
                    mini = diff;
                    ans = sum;
                }
                if(sum<tar)
                    j++;
                else
                    k--;
            }
        }
        return ans;
    }
}