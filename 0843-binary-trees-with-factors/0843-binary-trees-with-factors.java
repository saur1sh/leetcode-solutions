class Solution {
    public int numFactoredBinaryTrees(int[] arr) {
        Arrays.sort(arr);
        long ans = 0;
        final int mod = 1000000007;
        HashMap<Integer, Long> mp = new HashMap<>();
        mp.put(arr[0], 1L);
        for(int i=0; i<arr.length; i++) {
            long curr = 1;
            for(int j=0; j<i; j++) {
                if(arr[i]%arr[j]==0  && mp.containsKey(arr[i]/arr[j])){
                    curr = (curr%mod + (mp.get(arr[j])*mp.get(arr[i]/arr[j]))%mod)%mod;
                }
            }
            mp.put(arr[i], curr);
            ans = (ans%mod + curr%mod)%mod;
        }
        return (int)ans;
    }
}