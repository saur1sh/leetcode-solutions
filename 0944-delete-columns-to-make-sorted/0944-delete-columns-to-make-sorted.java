class Solution {
    public int minDeletionSize(String[] strs) {
        int ans = 0;
        for (int i = 0; i < strs[0].length(); i++) {
            char last = 'Z';
            for (int j = 0; j < strs.length; j++) {
                char curr = strs[j].charAt(i);
                if (last > curr) {
                    ans++;
                    break;
                } else {
                    last = curr;
                }
            }
        }
        return ans;
    }
}