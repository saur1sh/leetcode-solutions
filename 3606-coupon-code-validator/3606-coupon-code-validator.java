class Solution {

    public List<String> validateCoupons(String[] code, String[] businessLine, boolean[] isActive) {
        List<String> ans = new ArrayList<>();
        Comparator<Pair<String, String>> customComparator = (s1, s2) -> {
            int p1 = getPriority(s1.getValue());
            int p2 = getPriority(s2.getValue());

            int comp = Integer.compare(p1, p2);
            if (comp == 0) {
                return s1.getKey().compareTo(s2.getKey());
            } else {
                return comp;
            }
        };
        List<Pair<String, String>> st = new ArrayList<>();
        for (int i = 0; i < code.length; i++) {
            if (isActive[i] == true && PRIORITY_MAP.containsKey(businessLine[i]) && isValid(code[i])) {
                st.add(new Pair<>(code[i], businessLine[i]));
            }
        }
        st.sort(customComparator);
        st.forEach(s -> ans.add(s.getKey()));
        return ans;
    }

    private boolean isValid(String st) {
        if (st.isEmpty()) {
            return false;
        }
        for (int i = 0; i < st.length(); i++) {
            char x = st.charAt(i);
            if (Character.isLetterOrDigit(x) || x == '_') {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }

    private static final Map<String, Integer> PRIORITY_MAP = Map.of(
            "electronics", 1,
            "grocery", 2,
            "pharmacy", 3,
            "restaurant", 4);

    private static final int DEFAULT_PRIORITY = 100;

    private int getPriority(String s) {
        return PRIORITY_MAP.getOrDefault(s.toLowerCase(), DEFAULT_PRIORITY);
    }
}