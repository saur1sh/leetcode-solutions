class Solution {
    public int[] sortedSquares(int[] nums) {
        int l = 0, r = nums.length - 1;
        int[] ans = new int[nums.length];
        for (int i = nums.length - 1; i >= 0; i--) {
            int leftSquare = nums[l] * nums[l];
            int rightSquare = nums[r] * nums[r];
            if (leftSquare > rightSquare) {
                ans[i] = leftSquare;
                l++;
            } else {
                ans[i] = rightSquare;
                r--;
            }
        }
        return ans;
    }
}