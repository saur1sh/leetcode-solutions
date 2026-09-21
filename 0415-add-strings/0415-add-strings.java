class Solution {
    public String addStrings(String num1, String num2) {
        int carry = 0;
        StringBuilder ans = new StringBuilder("");
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        while (i >= 0 || j >= 0) {
            int a = i >= 0 ? num1.charAt(i) - '0' : 0;
            int b = j >= 0 ? num2.charAt(j) - '0' : 0;
            int val = a + b + carry;
            carry = val / 10;
            val = val % 10;
            ans.append(val);
            i--;
            j--;
        }
        if (carry > 0) {
            ans.append(carry);
        }
        return ans.reverse().toString();
    }
}