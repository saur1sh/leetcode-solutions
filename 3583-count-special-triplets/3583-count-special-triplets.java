class Solution {
    private static final int MOD = 1000000007;

    public int specialTriplets(int[] nums) {
        int n = nums.length;
        HashMap<Integer, Integer> mp = new HashMap<>();
        HashMap<Integer, Integer> pref = new HashMap<>();
        for (int x : nums) {
            mp.merge(x, 1, Integer::sum);
        }
        long ans = 0L;
        for (int x : nums) {
            int val = 2 * x;
            int total = mp.containsKey(val) ? mp.get(val) : 0;
            int left = pref.containsKey(val) ? pref.get(val) : 0;
            int right = total - left;
            if (x == 0) {
                right--;
            }
            pref.merge(x, 1, Integer::sum);
            ans = (ans + (1L*left * right)) % MOD;
        }
        return (int) ans;
    }
}