class Solution {
    private static final long mod = 1000000007L;

    public int countTrapezoids(int[][] points) {
        Map<Integer, Integer> mp = new HashMap<>();
        long ans = 0;
        long edgeSum = 0;

        for (int[] p : points) {
            mp.put(p[1], mp.getOrDefault(p[1], 0) + 1);
        }

        List<Integer> levels = new ArrayList<>(mp.keySet());
        Collections.sort(levels);

        for (int lvl : levels) {
            long curr = comb(mp.get(lvl), 2);
            ans = (ans + (edgeSum * curr) % mod) % mod;
            edgeSum = (edgeSum + curr) % mod;
        }

        return (int) ans;
    }

    public static long comb(int n, int r) {
        if (r <= 1) return n;
        if (r > n) return 0;
        if (r == 2) {
            return (long)n * (n - 1) / 2 % mod;
        }
        return 0;
    }
}