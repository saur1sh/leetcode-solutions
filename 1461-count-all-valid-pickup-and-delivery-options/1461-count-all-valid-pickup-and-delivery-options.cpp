class Solution {
public:
    int countOrders(int n) {
        long long ct = 1;
        const int mod = 1e9 +7;
        for(int i=2; i<=n; i++) {
            ct = (ct*(2*i-1)*i)%mod;
        }
        return (int)ct;
    }
};