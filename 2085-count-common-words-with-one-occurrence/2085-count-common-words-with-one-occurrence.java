class Solution {

    public static long hashString(String str) {
        long hash = 0;
        long p = 31;
        long mod = (long) (1e9 + 9);
        long p_pow = 1;

        for (int i = 0; i < str.length(); i++) {
            long charValue = str.charAt(i) - 'a' + 1;
            hash = (hash + charValue * p_pow) % mod;
            p_pow = (p_pow * p) % mod;
        }

        return hash;
    }

    public int countWords(String[] words1, String[] words2) {
        HashMap<Long, Integer> mp = new HashMap<>();
        Set<Long> uniqueIndex = new HashSet<>();
        for (int i = 0; i < words1.length; i++) {
            long hash = hashString(words1[i]);
            mp.put(hash, mp.getOrDefault(hash, 0) + 1);
        }
        for (int i = 0; i < words2.length; i++) {
            long hash = hashString(words2[i]);
            int occur = mp.getOrDefault(hash, 0);
            if (occur == 0) {
                continue;
            }
            if (occur == 1) {
                uniqueIndex.add(hash);
            }
            if (occur > 1 && uniqueIndex.contains(hash)) {
                uniqueIndex.remove(hash);
            }
            mp.put(hash, occur + 1);
        }
        return uniqueIndex.size();
    }
}