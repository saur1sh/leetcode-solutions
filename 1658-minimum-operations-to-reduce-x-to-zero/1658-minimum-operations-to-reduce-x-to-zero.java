class Solution {
    public int minOperations(int[] nums, int x) {
        int tar = 0;
        int n = nums.length;
        for (int e : nums) {
            tar += e;
        }
        tar -= x;
        if (tar < 0) {
            return -1;
        }
        if (tar == 0) {
            return n;
        }
        int l = 0, maxLen = 0, curr = 0;
        for (int r = 0; r < n; r++) {
            curr += nums[r];
            while (l <= r && curr > tar) {
                curr -= nums[l++];
            }
            if (tar == curr) {
                maxLen = Math.max(maxLen, r - l + 1);
            }
        }
        return maxLen > 0 ? n - maxLen : -1;
    }
}