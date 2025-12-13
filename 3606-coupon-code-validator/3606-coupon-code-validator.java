class Solution {
    private final Set<String> valid = Set.of("electronics", "grocery", "pharmacy", "restaurant");

    public List<String> validateCoupons(String[] code, String[] businessLine, boolean[] isActive) {
        List<String> ans = new ArrayList<>();
        Comparator<Pair<String, String>> customComparator = (s1, s2) -> {
            int comp = s1.getValue().compareTo(s2.getValue());
            if (comp == 0) {
                return s1.getKey().compareTo(s2.getKey());
            } else {
                return comp;
            }
        };
        List<Pair<String, String>> st = new ArrayList<>();
        for (int i = 0; i < code.length; i++) {
            if (isActive[i] == true && valid.contains(businessLine[i]) && isValid(code[i])) {
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
}