class Solution {
    public int[] findArray(int[] pref) {
        int n = pref.length;
        int[] ans = new int[n];
        for(int i=0; i<n; i++) {
            if(i==0)
                ans[0] = pref[0];
            else
                ans[i] = pref[i-1]^pref[i];
        }
        return ans;
    }
}