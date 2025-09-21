class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        int tar = 0;
        List<List<Integer>> ans = new ArrayList<>();
        HashSet<Long> set = new HashSet<>();
        for (int i = 0; i < nums.length; i++) {
            int ntar = tar - nums[i];
            int li = i + 1;
            int ri = nums.length - 1;
            while (li < ri) {
                int sum = nums[li] + nums[ri];
                if (sum > ntar) {
                    ri--;
                } else if (sum < ntar) {
                    li++;
                } else {
                    long hash = getHash(nums[i], nums[li], nums[ri]);
                    if (!set.contains(hash)) {
                        ans.add(List.of(nums[i], nums[li], nums[ri]));
                        set.add(hash);
                    }
                    li++;
                    ri--;
                }
            }
        }
        return ans;
    }

    private long getHash(int x, int y, int z) {
        long hash = x;
        hash *= 100000;
        hash += y;
        hash *= 100000;
        hash += z;
        return hash;
    }
}