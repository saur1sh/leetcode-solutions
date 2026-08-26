class Solution {
    public int missingNumber(int[] nums) {
        long sum = 0;
        int n = nums.length;
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
        }
        long ans = (n * (n + 1) / 2) - (long) sum;
        return (int) ans;
    }
}