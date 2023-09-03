class Solution {
public:

    int uniquePaths(int m, int n) {
        int N = m+n-2;
        int r = m-1;
        if(r>N) return 0;
        if(r==0 || N==r) return 1;
        double res = 0;
        for (int i = 0; i < r; i++) {
            res += log(N-i) - log(i+1);
        }
        return (int)round(exp(res));
    }
};