class Solution {
    public int countPartitions(int[] nums) {
        int sum = 0;
        for (int x : nums) {
            sum += x;
        }
        int lSum = 0;
        int ans = 0;
        for (int i = 0; i < nums.length - 1; i++) {
            lSum += nums[i];
            sum -= nums[i];
            if ((lSum % 2) == (sum % 2)) {
                ans += 1;
            }
        }
        return ans;
    }
}