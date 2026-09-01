class Solution {
    public int removeDuplicates(int[] nums) {
        int l = 1, r = 1, count = 1;
        while (r < nums.length) {
            if (nums[r] == nums[r - 1]) {
                count++;
            } else {
                count = 1;
            }
            if (count <= 2) {
                nums[l] = nums[r];
                l++;
            }
            r++;
        }
        return l;
    }
}