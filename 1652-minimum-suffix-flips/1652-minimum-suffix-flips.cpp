class Solution {
public:
    int minFlips(string a) {
        int res = a[0]-'0';
        for(int i=1; i<a.size(); i++) {
            res += a[i-1]!=a[i];
        }
        return res;
    }
};