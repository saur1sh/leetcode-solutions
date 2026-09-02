class Solution {
    public void duplicateZeros(int[] nums) {
        int zeros = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 0) {
                zeros++;
            }
        }
        for (int i = nums.length - 1; i >= 0; i--) {
            if (i + zeros < nums.length) {
                nums[i + zeros] = nums[i];
            }
            if (nums[i] == 0) {
                zeros--;
                if (i + zeros < nums.length)
                    nums[i + zeros] = nums[i];
            }
        }
    }
}