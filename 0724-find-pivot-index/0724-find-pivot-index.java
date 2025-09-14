class Solution {
    public int pivotIndex(int[] nums) {
        int[] sumLeft = new int[nums.length];
        int[] sumRight = new int[nums.length];
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                sumLeft[i] = nums[i];
                sumRight[n - i - 1] = nums[n - i - 1];
            } else {
                sumLeft[i] = sumLeft[i - 1] + nums[i];
                sumRight[n - i - 1] = sumRight[n - i] + nums[n - i - 1];
            }
        }
        if(sumLeft[0]==sumRight[0]) {
            return 0;
        }
        for (int i = 1; i < n - 1; i++) {
            if (sumLeft[i - 1] == sumRight[i + 1]) {
                return i;
            }
        }
        if(sumLeft[n-1]==sumRight[n-1]) {
            return n-1;
        }
        return -1;
    }
}