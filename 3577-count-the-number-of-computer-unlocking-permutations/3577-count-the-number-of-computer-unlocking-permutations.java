class Solution {
    private final int MOD = 1000000007;

    public int countPermutations(int[] comp) {
        long ans = 1;
        int n = comp.length;
        for (int i = 1; i < n; i++) {
            if (comp[i] <= comp[0]) {
                return 0;
            }
            ans = (ans * i) % MOD;
        }
        return (int) ans;
    }
}