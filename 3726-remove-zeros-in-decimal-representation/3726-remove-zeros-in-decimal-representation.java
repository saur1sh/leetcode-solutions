class Solution {
    public long removeZeros(long n) {
        long ans = 0;
        int pos = 0;
        while (n > 0) {
            long curr = n % 10;
            if (curr != 0) {
                ans += Math.pow(10, pos) * curr;
                pos++;
            }
            n /= 10;
        }
        return ans;
    }
}