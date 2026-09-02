class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int tar = -nums[i];
            int li = i + 1, ri = nums.length - 1;
            while (li < ri) {
                int sum = nums[li] + nums[ri];
                if (sum < tar) {
                    li++;
                } else if (sum > tar) {
                    ri--;
                } else {
                    ans.add(List.of(nums[i], nums[li], nums[ri]));
                    li++;
                    ri--;
                    while (li < ri && nums[li] == nums[li - 1]) {
                        li++;
                    }
                    while (li < ri && nums[ri] == nums[ri + 1]) {
                        ri--;
                    }
                }
            }
        }
        return ans;
    }
}