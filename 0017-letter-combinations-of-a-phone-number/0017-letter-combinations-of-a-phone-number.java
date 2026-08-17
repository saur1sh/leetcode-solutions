class Solution {
    private static String[] codes = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

    public List<String> letterCombinations(String digits) {
        return comb(digits, 0);
    }

    public List<String> comb(String digits, int idx) {
        if (idx == digits.length()) {
            ArrayList<String> ad = new ArrayList<>();
            ad.add("");
            return ad;
        }
        List<String> recResult = comb(digits, idx + 1);
        char ch = digits.charAt(idx);
        List<String> ans = new ArrayList<>();
        String code = codes[ch - '0'];
        for (String res : recResult) {
            for (int i = 0; i < code.length(); i++) {
                char c = code.charAt(i);
                String newString = c + res;
                ans.add(newString);
            }
        }
        return ans;
    }
}