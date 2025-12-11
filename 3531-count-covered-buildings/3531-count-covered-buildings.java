class Solution {
    public int countCoveredBuildings(int n, int[][] build) {
        if (n < 3) {
            return 0;
        }
        HashMap<Integer, TreeSet<Integer>> ym = new HashMap<>();
        HashMap<Integer, TreeSet<Integer>> xm = new HashMap<>();

        for (int i = 0; i < build.length; i++) {
            xm.computeIfAbsent(build[i][0], h -> new TreeSet()).add(build[i][1]);
            ym.computeIfAbsent(build[i][1], h -> new TreeSet()).add(build[i][0]);
        }

        int ans = 0;

        for (int i = 0; i < build.length; i++) {
            int x = build[i][0];
            int y = build[i][1];

            if (xm.containsKey(x) && ym.containsKey(y)) {
                var xh = xm.get(x);
                var yh = ym.get(y);
                if (isMiddle(xh, y) && isMiddle(yh, x)) {
                    ans++;
                }
            }
        }
        return ans;
    }

    public static boolean isMiddle(TreeSet<Integer> set, int value) {
        if (value > set.first() && value < set.last()) {
            return true;
        }
        return false;
    }

}