class Solution {
    private static final float MIN = Float.MIN_VALUE;

    public int countTrapezoids(int[][] points) {
        int n = points.length;
        HashMap<Integer, HashMap<Integer, Integer>> segments = new HashMap<>();
        HashMap<Integer, HashMap<Integer, Integer>> parallel_segments = new HashMap<>();

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                if(dx<0 || (dx==0 && dy<0)) {
                    dx = -dx;
                    dy = -dy;
                }
                int g = gcd(dx, Math.abs(dy));
                int sx = dx/g;
                int sy = dy/g;
                
                int line_param = sx*points[i][1] - sy*points[i][0];

                int key_norm = (sx<<12) | (sy+2000);
                int key_full = (dx<<12) | (dy+2000);

                segments.computeIfAbsent(key_norm, k -> new HashMap<>()).merge(line_param, 1, Integer::sum);
                parallel_segments.computeIfAbsent(key_full, k-> new HashMap<>()).merge(line_param, 1, Integer::sum);
            }
        }
        return calculate(segments) - calculate(parallel_segments)/2;
    }

    private int calculate(HashMap<Integer, HashMap<Integer, Integer>> mp) {
        long ans = 0;
        for(HashMap<Integer, Integer> inner: mp.values()) {
            long total = 0;
            for(int count: inner.values()) {
                total += count;
            }
            for(int count: inner.values()) {
                total -= count;
                ans += (long)count*total;
            }
        }
        return (int) ans;
    }

    private int gcd(int a, int b) {
        while(b!=0) {
            int temp = a%b;
            a = b;
            b = temp;
        }
        return Math.abs(a);
    }
    
}