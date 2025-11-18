class Solution {
    public String numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        String[] preecedingString = new String[] {
            "",
            "Thousand",
            "Million",
            "Billion"
        };
        String result = "";
        for (int i = 0; i < 4; i++) {
            if (num > 0 && num % 1000 > 0) {
                result = numToWords(num % 1000) + preecedingString[i] + " " + result;
            }
            num = num / 1000;
        }
        return result.trim();
    }

    private String numToWords(int num) {
        String[] digitString = new String[]{"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        String[] teenString = new String[]{"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen","Eighteen", "Nineteen"};
        String[] tenString = new String[]{"","","Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

        String result = "";
        if (num > 99) {
            result += digitString[num / 100] + " Hundred ";
        }
        num = num % 100;
        if (num > 9 && num < 20) {
            result += teenString[num % 10] + " ";
        } else {
            if (num > 19) {
                result += tenString[num / 10] + " ";
            }
            num = num % 10;
            if (num > 0) {
                result += digitString[num] + " ";
            }
        }
        return result;
    }
}