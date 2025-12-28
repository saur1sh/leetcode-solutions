class Solution {
    public int maximumCount(int[] nums) {
        if (nums.length == 1 && nums[0] != 0) {
            return 1;
        }
        int n = nums.length;
        int pos = positives(nums, n);
        int neg = negatives(nums, n);
        return Math.max(pos, neg);
    }

    private int positives(int[] nums, int n) {
        int high = n - 1;
        int low = 0;
        int ans = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] > 0) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if (nums[n - 1] <= 0) {
            return 0;
        }
        return n - ans;
    }

    private int negatives(int[] nums, int n) {
        int high = n - 1;
        int low = 0;
        int ans = high;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] < 0) {
                low = mid + 1;
                ans = mid;
            } else {
                high = mid - 1;
            }
        }
        if (nums[ans] >= 0) {
            return 0;
        }
        return ans + 1;
    }
}