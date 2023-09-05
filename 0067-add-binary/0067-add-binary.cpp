class Solution {
public:

    int sum_func(int a, int b) {
        if(a==1 && b==1)
            return 10;
        return a+b;
    }

    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int i=0, j=0, na=a.length(), nb=b.length(), sum;
        string ans="";
        int carry=0;
        while(i<na && j<nb) {
            sum = sum_func(a[i]-'0', b[i]-'0');
            sum = sum_func(sum, carry);
            carry = sum/10;
            ans += (sum%10)+'0';
            i++;
            j++;
        }
        while(i<na) {
            sum = sum_func(a[i]-'0', carry);
            carry = sum/10;
            ans += (sum%10)+'0';
            i++;
        }
        while(j<nb) {
            sum = sum_func(b[j]-'0', carry);
            carry = sum/10;
            ans += (sum%10) + '0';
            j++;
        }
        if(carry)
            ans+='1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};