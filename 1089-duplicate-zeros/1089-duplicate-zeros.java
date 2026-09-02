class Solution {
    public void duplicateZeros(int[] nums) {
        int l = 0;
        int[] ans = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            if (l >= nums.length)
                break;
            if (nums[i] == 0) {
                ans[l++] = 0;
                if (l < ans.length) {
                    ans[l++] = 0;
                } else {
                    break;
                }
            } else {
                ans[l++] = nums[i];
            }
        }
        for (int i = 0; i < nums.length; i++) {
            nums[i] = ans[i];
        }
    }
}