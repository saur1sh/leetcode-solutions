class Solution {
    public int smallestIndex(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            if (digSum(nums[i]) == i) {
                return i;
            }
        }
        return -1;
    }

    private int digSum(int n) {
        int c = 0;
        while (n > 0) {
            c += n % 10;
            n /= 10;
        }
        return c;
    }
}