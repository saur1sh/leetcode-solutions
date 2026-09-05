class Solution {
    private Set<Long> set = new HashSet<>();

    public boolean isHappy(int n) {
        while (true) {
            long sum = 0;
            while (n > 0) {
                int newNum = n % 10;
                sum += (newNum) * (newNum);
                n /= 10;
            }
            if (sum == 1) {
                return true;
            } else if (set.contains(sum)) {
                return false;
            }
            set.add(sum);
            n = (int) sum;
        }
    }
}