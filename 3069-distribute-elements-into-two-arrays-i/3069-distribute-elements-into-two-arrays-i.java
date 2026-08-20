class Solution {
    public int[] resultArray(int[] nums) {
        int n = nums.length;
        int[] arr1 = new int[n];
        int[] arr2 = new int[n];
        int idx1 = 0;
        int idx2 = 0;
        arr1[idx1++] = nums[0];
        arr2[idx2++] = nums[1];
        for (int i = 2; i < nums.length; i++) {
            if (arr1[idx1 - 1] > arr2[idx2 - 1]) {
                arr1[idx1++] = nums[i];
            } else {
                arr2[idx2++] = nums[i];
            }
        }
        System.arraycopy(arr1, 0, nums, 0, idx1);
        System.arraycopy(arr2, 0, nums, idx1, idx2);

        return nums;
    }
}