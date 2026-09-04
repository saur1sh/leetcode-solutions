class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        if (k == 0) {
            return 0;
        }
        int count = 0;
        int n = nums.length;
        int i = 0, j = 0;
        int prod = 1;
        while (j < n) {
            prod *= nums[j];
            while (prod >= k && i<n) {
                prod /= nums[i];
                i++;
            }
            count += j - i + 1;
            j++;
        }
        return count;
    }
}