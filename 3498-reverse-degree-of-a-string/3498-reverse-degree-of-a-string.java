class Solution {
    public int reverseDegree(String s) {
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            int val = 1 + 'z' - s.charAt(i);
            ans += (val * (i + 1));
        }
        return ans;
    }
}