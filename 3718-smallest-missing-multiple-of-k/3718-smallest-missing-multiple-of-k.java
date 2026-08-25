class Solution {
    public int missingMultiple(int[] nums, int k) {
        int[] vals = new int[101];
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] % k == 0) {
                vals[nums[i]]++;
            }
        }
        int largest = 1;
        for (int i = k; i < vals.length; i = i + k) {
            if (vals[i] == 0)
                return i;
            else if (vals[i] > 0) {
                largest = i / k;
            }
        }
        return (largest + 1) * k;
    }
}