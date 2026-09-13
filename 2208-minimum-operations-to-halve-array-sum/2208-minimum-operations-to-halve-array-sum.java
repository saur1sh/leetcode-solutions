class Solution {
    public int halveArray(int[] nums) {
        PriorityQueue<Double> pq = new PriorityQueue<>(Collections.reverseOrder());
        double total = 0;
        for (int i = 0; i < nums.length; i++) {
            total += nums[i];
            pq.add((double) nums[i]);
        }
        double tar = total / 2;
        int op = 0;
        while (!(total <= tar)) {
            double top = pq.poll();
            double minus = top / 2;
            total -= minus;
            pq.add(minus);
            op++;
        }
        return op;
    }
}