class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int tar = target - nums[i];
            if (mp.containsKey(tar)) {
                int[] ans = { mp.get(tar), i };
                return ans;
            } else {
                mp.put(nums[i], i);
            }
        }
        int[] ans = new int[2];
        return ans;
    }
}