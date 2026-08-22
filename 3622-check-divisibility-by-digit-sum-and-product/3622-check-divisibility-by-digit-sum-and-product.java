class Solution {
    public boolean checkDivisibility(int n) {
        int[] digs = new int[7];
        int temp = n;
        int id = 0;
        while (temp > 0) {
            digs[id] = temp % 10;
            temp = temp / 10;
            id++;
        }
        if (id < 7) {
            digs[id] = -1;
        }
        int dsum = 0;
        int dprod = 1;
        for (int i = 0; i < id; i++) {
            dsum += digs[i];
            dprod *= digs[i];
        }
        return n % (dprod + dsum) == 0 ? true : false;
    }
}