class Solution {
    public int countWords(String[] words1, String[] words2) {
        HashMap<String, Integer> mp = new HashMap<>();
        for (String word : words1) {
            mp.put(word, mp.getOrDefault(word, 0) + 1);
        }
        for (String word : words2) {
            Integer count = mp.get(word);
            if (count != null && count < 2) {
                mp.put(word, count - 1);
            }
        }
        int ans = 0;
        for (int count : mp.values()) {
            if (count == 0) {
                ans++;
            }
        }
        return ans;
    }
}