class Solution {
    public int countTriples(int n) {
        int ans = 0;
        long x = (long) n;
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int res = square(i) + square(j);
                long sqrt = (long) Math.sqrt(res);
                if (check(res, sqrt) && sqrt <= x) {
                    ans += 2;
                }
            }
        }
        return ans;
    }

    private int square(int x) {
        return x * x;
    }

    private boolean check(int x, double st) {
        if (x >= 0) {
            return (st * st == x);
        }
        return false;
    }
}