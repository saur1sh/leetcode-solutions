class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        int tar = 0;
        List<List<Integer>> ans = new ArrayList<>();
        for (int i = 0; i < nums.length-2; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int li = i + 1;
            int ri = nums.length - 1;
            int ntar = tar - nums[i];
            while (li < ri) {
                int sum = nums[li] + nums[ri];
                if (sum > ntar) {
                    ri--;
                } else if (sum < ntar) {
                    li++;
                } else {
                    ans.add(List.of(nums[i], nums[li], nums[ri]));
                    li++;
                    ri--;
                    while (li < ri && nums[li] == nums[li - 1])
                        li++;
                    while (li < ri && nums[ri] == nums[ri + 1])
                        ri--;
                }
            }
        }
        return ans;
    }
}