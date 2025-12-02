class Solution {
    private static final long MOD = 1000000007L;

    public int countTrapezoids(int[][] points) {
        Map<Integer, Integer> mp = new HashMap<>();
        long ans = 0;
        long edgeSum = 0;

        for (int[] p : points) {
            mp.put(p[1], mp.getOrDefault(p[1], 0) + 1);
        }

        for (int count: mp.values()) {
            if(count<2)
                continue;
            long curr = comb(count);
            ans = (ans + (edgeSum * curr) % MOD) % MOD;
            edgeSum = (edgeSum + curr) % MOD;
        }

        return (int) ans;
    }

private static long comb(int n) {
        if (n < 2) return 0;
        final long INV_2 = 500000004L; 

        long numerator = (long) n * (n - 1) % MOD;
        return (numerator * INV_2) % MOD;
    }
}