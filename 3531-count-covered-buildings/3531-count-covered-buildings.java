class Solution {
    public int countCoveredBuildings(int n, int[][] build) {
        if (n < 3) {
            return 0;
        }
        HashMap<Integer, int[]> ym = new HashMap<>();
        HashMap<Integer, int[]> xm = new HashMap<>();

        for (int i = 0; i < build.length; i++) {
            int x = build[i][0];
            int y = build[i][1];
            int[] aX = xm.computeIfAbsent(x, h -> new int[] { Integer.MAX_VALUE, Integer.MIN_VALUE });
            int[] aY = ym.computeIfAbsent(y, h -> new int[] { Integer.MAX_VALUE, Integer.MIN_VALUE });

            aX[0] = Math.min(aX[0], y);
            aX[1] = Math.max(aX[1], y);

            aY[0] = Math.min(aY[0], x);
            aY[1] = Math.max(aY[1], x);
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

    public static boolean isMiddle(int[] arr, int value) {
        if (value > arr[0] && value < arr[1]) {
            return true;
        }
        return false;
    }

}