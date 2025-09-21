class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList<>();

        for (int i = 0; i < nums.length - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int li = i + 1, ri = nums.length - 1;
            while (li < ri) {
                int sum = nums[i] + nums[li] + nums[ri];
                if (sum == 0) {
                    ans.add(Arrays.asList(nums[i], nums[li], nums[ri]));
                    li++;
                    ri--;
                    while (li < ri && nums[li] == nums[li - 1]) li++;
                    while (li < ri && nums[ri] == nums[ri + 1]) ri--;
                } else if (sum < 0) {
                    li++;
                } else {
                    ri--;
                }
            }
        }
        return ans;
    }
}