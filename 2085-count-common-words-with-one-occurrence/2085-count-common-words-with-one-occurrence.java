class Solution {
    public int countWords(String[] words1, String[] words2) {
        HashMap<String, Integer> mp1 = new HashMap<>();
        HashMap<String, Integer> mp2 = new HashMap<>();

        for (String word : words1) {
            mp1.put(word, mp1.getOrDefault(word, 0) + 1);
        }

        for (String word : words2) {
            mp2.put(word, mp2.getOrDefault(word, 0) + 1);
        }

        int count = 0;

        for (String word : words1) {
            if (mp1.get(word) == 1 && mp2.getOrDefault(word, 0) == 1) {
                count++;
            }
        }

        return count;
    }
}