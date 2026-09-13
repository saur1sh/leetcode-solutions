class Solution {
    public List<Integer> intersection(int[][] nums) {
        int[] arr = new int[1001];
        int n = nums.length;
        for (int i = 0; i < nums.length; i++) {
            for (int j = 0; j < nums[i].length; j++) {
                arr[nums[i][j]]++;
            }
        }
        List<Integer> ans = new ArrayList<>();
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] == n) {
                ans.add(i);
            }
        }
        return ans;
    }
}